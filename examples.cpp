#include "crypto.hpp"
#include <iostream>

using namespace std;

int main() {
  cout << "SHA-1 with 1 iteration" << endl;
  cout << Crypto::hex(Crypto::sha1("Test")) << endl << endl;
  
  cout << "SHA-1 with two iterations" << endl;
  cout << Crypto::hex(Crypto::sha1(Crypto::sha1("Test"))) << endl;
  
  // MD5
  cout << "MD5 with 1 iteration" << endl;
  cout << Crypto::hex(Crypto::md5("Test")) << endl;
  
  cout << "MD5 with 2 iterations" << endl;
  //cout << Crypto::hex(Crypto::md5(Crypto::md5("Test"))) << endl;
  
  // SHA-256
  cout << "SHA-256 with 1 iteration" << endl;
  cout << Crypto::hex(Crypto::sha256("Test")) << endl;
  
  cout << "SHA-256 with 2 iterations" << endl;
  cout << Crypto::hex(Crypto::sha256(Crypto::sha256("Test"))) << endl;
  
  
  // SHA-512
  cout << "SHA-512 with 1 iteration" << endl;
  cout << Crypto::hex(Crypto::sha512("Test")) << endl;
  
  cout << "SHA-512 with 2 iterations" << endl;
  cout << Crypto::hex(Crypto::sha512(Crypto::sha512("Test"))) << endl;
  
  

  cout << "The derived key from the PBKDF2 algorithm" << endl;
  cout << Crypto::hex(Crypto::pbkdf2("Password", "Salt")) << endl;
}
