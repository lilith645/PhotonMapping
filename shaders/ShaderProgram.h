#ifndef SHADERPROGRAM_H
#define SHADERPROGRAM_H

class ShaderProgram {
  public:
    ShaderProgram() {
      
    }
    
    void init(std::string vertex_file_path, std::string fragment_file_path) {
      vertexShaderID = loadShader(vertex_file_path, GL_VERTEX_SHADER);
      fragmentShaderID = loadShader(fragment_file_path, GL_FRAGMENT_SHADER);
      
      GLint Result = GL_FALSE;
      int InfoLogLength;
      
      printf("Linking program\n");
      programID = glCreateProgram();
      glAttachShader(programID, vertexShaderID);
      glAttachShader(programID, fragmentShaderID);

      bindAttributes();

      glLinkProgram(programID);

      // Check the program
      glGetProgramiv(programID, GL_LINK_STATUS, &Result);
      glGetProgramiv(programID, GL_INFO_LOG_LENGTH, &InfoLogLength);
      if ( InfoLogLength > 0 ){
        std::vector<char> ProgramErrorMessage(InfoLogLength+1);
        glGetProgramInfoLog(programID, InfoLogLength, NULL, &ProgramErrorMessage[0]);
        printf("%s\n", &ProgramErrorMessage[0]);
      }
      
      getAllUniformLocations();
    }
    
    virtual void bindAttributes()=0;
    
    void start() {
      glUseProgram(programID);
    }
    
    void stop() {
      glUseProgram(0);
    }
    
    void clean() {
      stop();
      
      glDetachShader(programID, vertexShaderID);
      glDetachShader(programID, fragmentShaderID);
      glDeleteShader(vertexShaderID);
      glDeleteShader(fragmentShaderID);
      glDeleteProgram(programID);
    }
  protected:
    
    virtual void getAllUniformLocations()=0;
    
    void bindAttribute(int attribute, std::string varName) {
      glBindAttribLocation(programID, attribute, varName.c_str());
    }
    
    GLuint getUniformLocation(std::string uniformName) {
      return glGetUniformLocation(programID, uniformName.c_str());
    }
    
    void loadBool(int location, bool value) {
      float toLoad = 0;
      if(value)
        toLoad = 1;
      glUniform1f(location, toLoad);
    }
    
    void loadFloat(int location, float value) {
      glUniform1f(location, value);
    }
    
    void loadVector(int location, glm::vec3 vector) {
      glUniform3f(location, vector.x, vector.y, vector.z);
    }
    
    void loadMatrix(int location, glm::mat4 matrix) {
      glUniformMatrix4fv(location, 1, GL_FALSE, glm::value_ptr(matrix));
    }
    
    int loadShader(std::string file_path, int type) {
      // Read the Vertex Shader code from the file
      std::string shaderCode;
      std::ifstream shaderStream(file_path, std::ios::in);
      if(shaderStream.is_open()){
        std::string Line = "";
        while(getline(shaderStream, Line))
          shaderCode += "\n" + Line;
        shaderStream.close();
      }else{
        printf("Impossible to open %s. \n", file_path.c_str());
        getchar();
        return 0;
      }

      GLint Result = GL_FALSE;
      int InfoLogLength;

      GLuint shaderID = glCreateShader(type);

      // Compile Vertex Shader
      printf("Compiling shader : %s\n", file_path.c_str());
      char const * sourcePointer = shaderCode.c_str();
      glShaderSource(shaderID, 1, &sourcePointer , NULL);
      glCompileShader(shaderID);

      // Check Vertex Shader
      glGetShaderiv(shaderID, GL_COMPILE_STATUS, &Result);
      glGetShaderiv(shaderID, GL_INFO_LOG_LENGTH, &InfoLogLength);
      if ( InfoLogLength > 0 ){
        std::vector<char> shaderErrorMessage(InfoLogLength+1);
        glGetShaderInfoLog(shaderID, InfoLogLength, NULL, &shaderErrorMessage[0]);
        printf("%s\n", &shaderErrorMessage[0]);
      }
      
      return shaderID;
    }
    
    GLuint programID;
    GLuint vertexShaderID;
    GLuint fragmentShaderID;
};

#endif
