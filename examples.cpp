#include "crypto.hpp"
#include <iostream>

using namespace std;


string key = "ab29d7b5c589e18b52261ecba1d3a7e7cbf212c6";
string salt = "Saltet til Ola";
int iterations = 2048;
int keylength = 160 / 8;
string alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";

void Check(){
  bool done = false;
  while(done == false){
    char password[3];
    for (char p1 : alphabet) {
      for (char p2 : alphabet) {
        for (char p3 : alphabet) {
          password[0] = p1;
          password[1] = p2;
          password[2] = p3;
          cout << "curr: " << password << endl;
          
          if(key == Crypto::hex(Crypto::pbkdf2(password, salt, iterations, keylength))){
            cout << "Password: " << password << endl;
            done = true;
            exit(0);
          }
        }
      }
    }
  }
  exit(0);
}



int main() {
  cout << "SHA-1 with 1 iteration" << endl;
  cout << Crypto::hex(Crypto::sha1("Test")) << endl << endl;
  
  cout << "SHA-1 with 2 iterations" << endl;
  cout << Crypto::hex(Crypto::sha1(Crypto::sha1("Test"))) << endl << endl;
  
  // MD5
  cout << "MD5 with 1 iteration" << endl;
  cout << Crypto::hex(Crypto::md5("Test")) << endl << endl;
  
  //cout << "MD5 with 2 iterations" << endl;
  //cout << Crypto::hex(Crypto::md5(Crypto::md5("Test"))) << endl;
  
  // SHA-256
  cout << "SHA-256 with 1 iteration" << endl;
  cout << Crypto::hex(Crypto::sha256("Test")) << endl << endl;
  
  cout << "SHA-256 with 2 iterations" << endl;
  cout << Crypto::hex(Crypto::sha256(Crypto::sha256("Test"))) << endl << endl;
  
  
  // SHA-512
  cout << "SHA-512 with 1 iteration" << endl;
  cout << Crypto::hex(Crypto::sha512("Test")) << endl << endl;
  
  cout << "SHA-512 with 2 iterations" << endl;
  cout << Crypto::hex(Crypto::sha512(Crypto::sha512("Test"))) << endl << endl;
  
  

  cout << "The derived key from the PBKDF2 algorithm" << endl;
  cout << Crypto::hex(Crypto::pbkdf2("Password", "Salt")) << endl;
  
  
  
  cout << "Pas key" << endl;
  cout << Crypto::hex(Crypto::pbkdf2("QwE", salt, iterations , keylength)) << endl << endl ;
  
  Check();
}
