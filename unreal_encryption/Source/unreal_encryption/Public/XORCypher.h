// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

/**
 * 
 */
class UNREAL_ENCRYPTION_API XORCypher
{
public:
	XORCypher();
	~XORCypher();

	// Note: Encrypting and Decrypting use the same function
	FString EncryptText(char key, FString text);
	FString EncryptText(FString key, FString text);
};
