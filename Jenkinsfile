pipeline {
  agent any
  stages {
    stage('Clone') {
      steps {
        echo 'Cloning repo.'
        git(url: 'https://github.com/compilerking420/cproj.git', branch: 'master')
      }
    }
    stage('Build') {
      steps {
        sh 'gcc -v -g -Wall -c main.c && gcc -v -g -Wall -c rndnum.c && gcc -v -g -o cproj main.o rndnum.o'
      }
    }
    stage('Compiled binary verification.') {
      steps {
        echo 'Checking if compiled binary exists.'
        fileExists 'cproj'
      }
    }
    stage('Binary smoke tests') {
      steps {
        parallel(
          "Binary smoke tests": {
            echo 'Running binary smoke tests...'
            
          },
          "Test1": {
            sh './cprog'
            catchError() {
              error 'Error in binary running.'
            }
            
            
          }
        )
      }
    }
    stage('error') {
      steps {
        echo 'Test result:'
      }
    }
  }
  environment {
    server = 'server'
  }
}