pipeline {
  agent none
  stages {
    stage('Clone') {
      steps {
        git(url: 'https://github.com/compilerking420/cproj.git', branch: 'master')
      }
    }
    stage('Build') {
      steps {
        sh 'gcc -v -g -Wall -c main.c && gcc -v -g -Wall -c rndnum.c && gcc -v -g -o cproj main.o rndnum.o'
      }
    }
  }
  environment {
    server = 'server'
  }
}