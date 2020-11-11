//////////////////////////////////////////////////
// Christopher Robertson 2020.
// https://github.com/Koltonix
// Copyright (c) 2020. All rights reserved.
//////////////////////////////////////////////////
#pragma once

#include "CoreMinimal.h"

#include <map>

/**
 * 
 */
class UNREAL_ENCRYPTION_API CeasarCypher
{
public:
	CeasarCypher();
	~CeasarCypher();

	FString EncryptText(int key, FString text);
	FString DecryptText(int key, FString encryptedText);
	std::map<char, char> GetShiftedAlphabet(int key);
	void PrintShiftedCypher(std::map<char, char> shiftedCypher);

private:
	FString m_textToEncrypt = "Hello, my name is Christopher!";
	int m_shiftKey = 1;
};
