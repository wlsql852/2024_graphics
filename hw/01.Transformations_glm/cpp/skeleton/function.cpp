/* 
파일 실행 방법
해당 파일이 속한 폴더로 이동후(cd hw/01.Transformations_glm/cpp/skeleton)
make : 실행파일 생성
./Transform : 실행파일 출력
 */


/* // 이동변환 행렬(traslate)
//m은 4x4 크기의 단위행렬, v는 (dx,dy,dz)만큼 이동을 나타낸 벡터
//m은 glm::mat4(1.0f), v는 문제를 따름
template<typename T>
detail::tmat4x4<T> translate (detail::tmat4x4<T> const &m, detail::tvec3<T> const &v)

//회전변환 행렬(rotate)
//: 단위 백터 u=(u1,u2,u3)를 회전축으로 하여(axis), 원점을 중심으로 쎄터(angle)만큼 회전하는 회전변환, m은 4x4 크기의 단위행렬
//m은 glm::mat4(1.0f), 쎄터는 glm::radians(쎄터)이며,쎄터와 u는 문제를 따름
template<typename T>
detail::tmat4x4<T> rotate (detail::tmat4x4 const &m, T const &angle, detail::tvec3<T> const &axis)

//확대축소 행렬(scailing)
//x,y,z축으로 각각 sx,sy,sz만큼(v) 원점을 기준으로 크기를 변화시키는 확대축소변환은 다음 함수를 사용한다, m은 4x4 크기의 단위행렬
//m은 glm::mat4(1.0f), v는 문제를 따름
template<typename T>
detail::tmat4x4<T> scale (detail::tmat4x4<T> const &m, detail::tvec3<T> const &v)

//시점변환 행렬(view transform)
//3차원에서 카메라의 자세와 관계된 시점변환은 다음과 같이 두 행렬의 곱으로 표현된 4x4 행렬로 표현되며 다음 함수를 사용한다
//eye : 카메라 위치벡터, center : 바라보는 대상의 위치벡터, up : 카메라의 up-vector
//셋다 문제에 나와있음
template<typename T>
detail::tmat4x4<T> lookAt (detail::tvec3<T> const &eye, detail::tvec3<T> const &center, detail::tvec3<T> const &up)

//투영변환 행렬(projection matrix)
//3차원에서 카메라의 투영변환은 직교투영인지 원근투영인지에 따라 다음과 같은 4x4 행렬로 표현된다

//직교투영행렬(orthographic projection
//3차원 카메라의 직교투영변환은 다음과 같은 4x4 행렬로 표현된다. 단 l,r,b,t,n,f는 각각 left, rignt, bottom, top, near, far의 약어이다
//전부 문제에 나와있음
template<typename T>
detail::tmat4x4<T> ortho (T const &left, T const &right, T const & bottom, T const &top, T const &zNear, T const &zFar)

//원근투영행렬(perspective projection)
// 절두체행렬, 단 l,r,b,t,n,f는 각각 left, rignt, bottom, top, near, far의 약어이다
//전부 문제에 나와있음
template<typename T>
detail::tmat4x4<T> frunstum (T const &left, T const &right, T const & bottom, T const &top, T const &near, T const &far)

//원근투영행렬
//fovy:시야각 , aspect:aspect값, near:가까운 거리, far:먼거리
//전부 문제에 나와있음, 단, 시야각은 glm::radians(쎄터)로 써야함
template<typename T>
detail::tmat4x4<T> perspective (T const &fovy, T const &aspect, T const &near, T const &far) */