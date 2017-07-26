pipeline {
  agent any
  stages {
    stage('Clone') {
      steps {
        echo 'Cloning repo.'
        git(url: 'https://github.com/compilerking420/cproj.git', branch: 'master') // source repo
      }
    }
    stage('Build') {
      steps {
        sh 'gcc -v -g -Wall -c main.c && gcc -v -g -Wall -c rndnum.c && gcc -v -g -o cproj main.o rndnum.o' // compile
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
        parallel( // Run in parallel
          "Binary smoke tests": {
            echo 'Running binary smoke tests...'
            
          },
          "Test1": {
            echo 'test 1 running...'
            sh './cproj'
            
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
    stage('deploy artifacts') {
      steps {
        echo 'Deploying binary and Jenkins log...'
        sh 'mkdir -v /tmp/artifacts'
        sh 'cp -v cproj /tmp/artifacts/'
        dir(path: '/tmp/artifacts') {
          sh 'pwd' // print out current folder for artifacts handling.
          sh 'cp -v /var/lib/jenkins/jobs/compilerking420/jobs/cproj/branches/master/builds/`ls -tr | tail -n 1`/log .' // fetch log.
          sh 'rm -rfv .git' // Start fresh git
          sh 'git init' // Initnialize git
          sh 'git add cproj log' // *** Artifacts to push to deploy repo ***
          sh 'git commit -m "Commit by Jenkins"' // Commit message
          sh 'git remote add origin git@github.com:compilerking420/cproj-deploy.git' // Set origin path
          sh 'git remote set-url origin git@github.com:compilerking420/cproj-deploy.git' // Switch to git by ssh-key
          sh 'git push -f origin master' // Push artifacts forced, overwriting all files in repo.
        }
      }
    }
    stage('Final') {
      steps {
        echo 'Built, tested and deployed successfully.' // Message when successful.
      }
    }
  }
  environment {
    server = 'server'
  }
}
