#include "Camera.h"

// TODO: fill up the following function properly 
void Camera::set_rotation(const glm::quat& _q)
{
  // Set camera rotation
  glm::mat3 rotationMatrix = glm::mat3_cast(_q);
  right_dir_ = rotationMatrix[0];    // +x_cam direction
  up_dir_ = rotationMatrix[1];       // +y_cam direction
  front_dir_ = -rotationMatrix[2];   // -z_cam direction
}

// TODO: re-write the following function properly 
const glm::quat Camera::get_rotation() const
{
  // Calculate rotation quaternion from current direction vectors
    glm::mat3 rotationMatrix(
        right_dir_,  // +x_cam direction
        up_dir_,     // +y_cam direction
        -front_dir_  // -z_cam direction
    );
    return glm::quat_cast(rotationMatrix);
}
  //return glm::quat(1.0f, 0.0f, 0.0f, 0.0f);

// TODO: fill up the following function properly 
void Camera::set_pose(const glm::quat& _q, const glm::vec3& _t)
{
  // Set camera rotation
    glm::mat3 rotationMatrix = glm::mat3_cast(_q);
    front_dir_ = -rotationMatrix[2]; // -z_cam direction
    right_dir_ = rotationMatrix[0];   // +x_cam direction
    up_dir_ = rotationMatrix[1];      // +y_cam direction

    // Set camera position
    position_ = _t;
}

// TODO: fill up the following function properly 
void Camera::get_pose(glm::quat& _q, glm::vec3& _t) const
{
   // Calculate rotation quaternion from the camera's direction vectors
    _q = glm::quat_cast(glm::mat3(right_dir_, up_dir_, -front_dir_));

    // Get camera position
    _t = position_;
}

// TODO: rewrite the following function properly 
const glm::mat4 Camera::get_pose() const
{
  glm::vec3 position = Camera::position();
  glm::vec3  up = Camera::up_direction();
  glm::vec3  center = glm::cross(Camera::front_direction(),Camera::right_direction());
  return  glm::lookAt(position,center,up);
}

// TODO: fill up the following function properly 
void Camera::set_pose(const glm::mat4& _frame)
{
      // Extract right, up, and front vectors from the given frame
    glm::vec3 right = glm::vec3(_frame[0]);
    glm::vec3 up = glm::vec3(_frame[1]);
    glm::vec3 front = glm::vec3(-_frame[2]); // Negate the z-axis to get the front vector

    // Normalize the vectors
    right = glm::normalize(right);
    up = glm::normalize(up);
    front = glm::normalize(front);

    // Update camera direction vectors and position
    right_dir_ = right;
    up_dir_ = up;
    front_dir_ = front;

    // Extract camera position from the fourth column of the frame
    glm::vec3 position = glm::vec3(_frame[3]);

    // Update camera position
    position_ = position;
  // +x_cam: right direction of the camera    (it should be a unit vector whose length is 1)
  // right_dir_ = ..... ; // +x
  // +y_cam: up direction of the camera       (it should be a unit vector whose length is 1)   
  // up_dir_    = ..... ;    // +y
  // -z_cam: front direction of the camera    (it should be a unit vector whose length is 1)
  // front_dir_ = ..... ;    // -z
  // pos_cam: position of the camera
  // position_  = ..... ;    // pos
}

// TODO: fill up the following function properly 
void Camera::set_pose(const glm::vec3& _pos, const glm::vec3& _at, const glm::vec3& _up_dir)
{
  // Calculate the front direction vector by subtracting the camera position from the "at" point
    glm::vec3 front = glm::normalize(_at - _pos);

    // Calculate the right direction vector using cross product of front and up vectors
    glm::vec3 right = glm::normalize(glm::cross(front, _up_dir));

    // Calculate the up direction vector using cross product of right and front vectors
    glm::vec3 up = glm::normalize(glm::cross(right, front));

    // Update camera direction vectors and position
    front_dir_ = front;
    right_dir_ = right;
    up_dir_ = up;
    position_ = _pos;
  // up_dir_    = ..... ;
  // front_dir_ = ..... ;    // -z_cam direction
  // right_dir_ = ..... ;    // +x_cam direction
  // up_dir_    = ..... ;    // +y_cam direction

  // position_  = ..... ;      // pos
}

// TODO: rewrite the following function properly 
const glm::mat4 Camera::get_view_matrix() const
{
  // Calculate the view matrix using the glm::lookAt function
  return glm::lookAt(position_, position_ + front_dir_, up_dir_);
  //return glm::mat4(1.0f);
}

// TODO: rewrite the following function properly 
const glm::mat4 Camera::get_projection_matrix() const
{
  if (mode_ == kPerspective)
    {
        float fovy = fovy_;
        float aspect = aspect_;
        float near = near_;
        float far = far_;
        return glm::perspective(glm::radians(fovy), aspect, near, far);
    }
    else
    {
        float ortho_scale = ortho_scale_;
        float aspect = aspect_;
        float near = near_;
        float far = far_;
        return glm::ortho(-ortho_scale * aspect, ortho_scale * aspect, -ortho_scale, ortho_scale, near, far);
    }
  
  // TODO: Considering the followings,
  //       You must return a proper projection matrix
  //       i) camera mode: it can be either kOrtho or kPerspective
  //       ii) zoom-in/-out: if the camera mode is kOrtho, 
  //                         utilize ortho_scale_ for zoom-in/-out
  //                         if the camera mode is kPerspective,
  //                         utilize fovy_ for zoom-in/-out
  //       iii) aspect ratio: utilize aspect_ in the both camera modes
  //       iv) near/far clipping planes: utilize near_, far_
}

// TODO: fill up the following functions properly 
void Camera::move_forward(float delta)
{
  // 정면 방향으로 이동할 벡터 계산
  glm::vec3 movement = front_dir_ * delta;
  
  // 현재 위치 업데이트
  position_ += movement;
}

// TODO: fill up the following functions properly 
void Camera::move_backward(float delta)
{
  // 정면 방향으로 -이동할 벡터 계산
  glm::vec3 movement = -front_dir_ * delta;
  
  // 현재 위치 업데이트
  position_ += movement;
}

// TODO: fill up the following functions properly 
void Camera::move_left(float delta)
{
  // 좌측 방향으로 이동할 벡터 계산
  glm::vec3 movement = -right_dir_ * delta;
  
  // 현재 위치 업데이트
  position_ += movement;
}

// TODO: fill up the following functions properly 
void Camera::move_right(float delta)
{
  // 우측 방향으로 이동할 벡터 계산
  glm::vec3 movement = right_dir_ * delta;
  
  // 현재 위치 업데이트
  position_ += movement;
}

// TODO: fill up the following functions properly 
void Camera::move_up(float delta)
{
  // 위쪽 방향으로 이동할 벡터 계산
  glm::vec3 movement = up_dir_ * delta;
  
  // 현재 위치 업데이트
  position_ += movement;
}

// TODO: fill up the following functions properly 
void Camera::move_down(float delta)
{
// 아래쪽 방향으로 이동할 벡터 계산
  glm::vec3 movement = -up_dir_ * delta;
  
  // 현재 위치 업데이트
  position_ += movement;
}
