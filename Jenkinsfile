pipeline {
  agent none
  stages {
    stage('Clone') {
      steps {
        echo 'Cloning repo.'
      }
    }
    stage('Build') {
      steps {
        sh 'sh \'gcc -v -g -Wall -c main.c && gcc -v -g -Wall -c rndnum.c && gcc -v -g -o cproj main.o rndnum.o\''
      }
    }
  }
  environment {
    server = 'server'
  }
}