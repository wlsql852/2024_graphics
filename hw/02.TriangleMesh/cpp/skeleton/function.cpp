/* 
파일 실행 방법
해당 파일이 속한 폴더로 이동후 (cd hw/02.TriangleMesh/cpp/skeleton)
make : 실행파일 생성
./mesh : 실행파일 출력
창이 열리면 오른쪽 숫자판이 아닌 글자 위쪽의 숫자을 눌러 대상을 바꾼다
//세개의 vlist_triangle.hpp파일에서 index데이터를 cube는 GLuindex에서 GLubyte로, avocado와 donut은 GLushort로 바꾸고 시작
 */

/*
1. main{
    glfwCreateWindow
    glfwTerminate
    glfwMakeContextCurrent
    glGetString
    --------------------
    glfwSetKeyCallback
    init_shader_program  - 3번 
    init_buffer_objects  -6번(VBO 초기화)
    while(glfwWindowShouldClose){
        glClearcolor
        glClear
        glEnable
        set_transform    -7번
        render_object    -8번
        glfwSwapBuffers
        glfwPollEvents
    }
    glfwTerminate
}
*/

/*
update_buffer_objects
*/

/*
2. create_shader_from_file{
    glCreateShader
    glShaderSource
    glCompileShader
    glGetShaderiv
    glGetShaderInfoLog
    glDeleteShader
}
*/
/*
3. init_shader_program {
    create_shader_from_file   //2번
    glCreateProgram
    glAttachShader
    glLinkProgram
    glGetProgramiv
    glGetProgramInfoLog
    glDeleteProgram
    glGetUniformLocation
    glGetAttribLocation
}
*/

/*
4.  key_callback {
    update_buffer_objects
}
*/
/*
5. update_buffer_objects {
    glBindBuffer
    glBufferDataS
}
*/
/*
6. init_buffer_objects {
    glGenBuffers
    update_buffer_obejects  //5번
}
*/
/*
7.set_transform {}
*/
/*
8. render_objects {
    glUseProgram
    flUniformMatrix4fv
    glBindBuffer
    glEnableVertexAttribArray
    glVertexAttribPointer
    glBindBuffer
    glEnableVertexAttribArray
    glVertexAttribPointer
    glDrawArrays - ?
    glDisableBertexAttribArray
    glUseProgram
}
*/