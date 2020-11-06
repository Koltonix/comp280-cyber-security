// Fill out your copyright notice in the Description page of Project Settings.

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

private:
	FString m_textToEncrypt = "Hello, my name is Christopher!";
	int m_shiftKey = 1;
};
