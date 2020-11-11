//////////////////////////////////////////////////
// Christopher Robertson 2020.
// https://github.com/Koltonix
// Copyright (c) 2020. All rights reserved.
//////////////////////////////////////////////////

#include "CypherTest.h"
#include "CeasarCypher.h"
#include "XORCypher.h"

// Sets default values
ACypherTest::ACypherTest()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

}

// Called when the game starts or when spawned
void ACypherTest::BeginPlay()
{
	Super::BeginPlay();

	//CeasarCypher cypher = CeasarCypher();
	XORCypher xorCypher = XORCypher();
}

// Called every frame
void ACypherTest::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

