#version 120                  // GLSL 1.20

// for phong shading
varying vec3 v_position_wc;
varying vec3 v_normal_wc;  //n

uniform vec3 u_light_position;  
uniform vec3 u_light_ambient;   //La
uniform vec3 u_light_diffuse;  //Ld
uniform vec3 u_light_specular;  //Ls

uniform vec3  u_obj_ambient;  //Ka
uniform vec3  u_obj_diffuse;  //Kd
uniform vec3  u_obj_specular;  //Ks
uniform float u_obj_shininess;  //alpha

uniform vec3 u_camera_position;
uniform mat4 u_view_matrix;

vec3 directional_light() 
{
  vec3 color = vec3(0.0);
  vec3 normal_wc   = normalize(u_normal_wc);   //n
  vec3 light_dir = normalize(u_light_position);  //l

  // ambient
  color += (u_light_ambient * u_obj_ambient);  //La*Ka
  
  // diffuse 
  float ndotl = max(dot(normal_wc, light_dir), 0.0);    //n.l
  color += (ndotl * u_light_diffuse * u_obj_diffuse);   //ndotl * Ld * Kd

  // specular
  vec3 view_dir = normalize(u_camera_position - position_wc);  /v
  vec3 reflect_dir = reflect(-light_dir, normal_wc);   //r

  float rdotv = max(dot(view_dir, reflect_dir), 0.0);  //v.r
  color += (pow(rdotv, u_obj_shininess) * u_light_specular * u_obj_specular);  //(rdotv)^alpha * Ls * Ks

  return color;
}

void main()
{
  vec3 result = directional_light();
	gl_FragColor = vec4(result, 1.0f);
}