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
      sh '$FAILURES = 0'
      sh '$SUCCESSFUL = 0'
      steps {
        parallel(
          "Binary smoke tests": {
            echo 'Running binary smoke tests...'
            
          },
          "Test1": {
            echo 'test 1 running...'
            sh './cproj'
            sh 'if [ $? != 0 ]; then ((SUCCESSFUL++)); else ((FAILURES++)); fi'
          },
          "Test2": {
            sh './cproj'
            
          },
          "Test3": {
            sh './cproj'
            
          },
          "Test4": {
            sh './cproj'
            
          },
          "Test5": {
            sh './cproj'
            
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
