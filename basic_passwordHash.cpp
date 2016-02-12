#include <cryptopp/hex.h>
#include <cryptopp/sha.h>
#include <cryptopp/base64.h>
#include <iostream>
#include <string>

int main()
{
    CryptoPP::SHA256 hash;
    byte digest[CryptoPP::SHA256::DIGESTSIZE];
    std::string username, password, salt, output;
    std::cout << "Enter username: ";
    std::getline(std::cin,username);
    std::cout << std::endl << "Enter password: ";
    std::getline(std::cin,password);
    salt = username + password;

    hash.CalculateDigest(digest,(const byte *)salt.c_str(),salt.size());

    CryptoPP::HexEncoder encoder;
    CryptoPP::StringSink *SS = new CryptoPP::StringSink(output);
    encoder.Attach(SS);
    encoder.Put(digest,sizeof(digest));
    encoder.MessageEnd();

    std::cout << "The username/password salted hash is => " << output << std::endl;
    return 0;
}
