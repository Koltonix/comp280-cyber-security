// Fill out your copyright notice in the Description page of Project Settings.


#include "XORCypher.h"

XORCypher::XORCypher()
{
	FString encrypted = EncryptText("ABCDE", "Hello");
	GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, encrypted);
	FString decrypted = EncryptText("ABCDE", encrypted);
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
		GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, text);
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
		GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, text);
	}
	return text;
}
