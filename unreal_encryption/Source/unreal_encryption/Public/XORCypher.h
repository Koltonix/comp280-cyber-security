//////////////////////////////////////////////////
// Christopher Robertson 2020.
// https://github.com/Koltonix
// Copyright (c) 2020. All rights reserved.
//////////////////////////////////////////////////
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
