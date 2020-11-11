//////////////////////////////////////////////////
// Christopher Robertson 2020.
// https://github.com/Koltonix
// Copyright (c) 2020. All rights reserved.
//////////////////////////////////////////////////

#include "XORCypher.h"

XORCypher::XORCypher()
{
	FString encrypted = EncryptText('C', "Hello, my name is Christopher Robertson!");
	GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, encrypted);
	FString decrypted = EncryptText('C', encrypted);
	GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, decrypted);
}

XORCypher::~XORCypher()
{
}


// Source: https://www.geeksforgeeks.org/xor-cipher/
FString XORCypher::EncryptText(char key, FString text)
{
	for (int i = 0; i < text.Len(); i++)
	{
		text[i] = text[i] ^ key;
	}
	return text;
}

// Source: https://www.geeksforgeeks.org/xor-cipher/
FString XORCypher::EncryptText(FString key, FString text)
{
	if (key.Len() != text.Len())
		return "FAILED - KEY LENGTH MUST EQUAL TEXT LENGTH";

	for (int i = 0; i < text.Len(); i++)
	{
		text[i] = text[i] ^ key[i];
	}
	return text;
}
