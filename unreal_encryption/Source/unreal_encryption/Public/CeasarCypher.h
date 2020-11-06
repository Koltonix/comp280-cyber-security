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

	char* EncryptText(char* text);
	std::map<char, char> GetShiftedAlphabet(int key);

private:
	std::map<char, char> m_shiftedAlphabet;
	char* m_textToEncrypt = "abc";
	int m_shiftKey = 0;
};
