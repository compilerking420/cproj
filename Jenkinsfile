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
    stage('Preparing test counters') {
      steps{
         sh 'export FAILURES=0'
         sh 'export SUCCESSFUL=0'        
      }
    }
    stage('Binary smoke tests') {
      steps {
        parallel(
          "Binary smoke tests": {
            echo 'Running binary smoke tests...'
          },
          "Test1": {
            echo 'test 1 running...'
            sh './cproj'
            sh 'if [ $? -eq 0 ]; then { echo "Successful run." && SUCCESSFUL=$((SUCCESSFUL+1)) } else { echo "Failed run." && FAILURES=$((FAILURES+1)) }; fi'
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
