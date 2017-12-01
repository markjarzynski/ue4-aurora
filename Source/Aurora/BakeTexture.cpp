// Fill out your copyright notice in the Description page of Project Settings.


#include "BakeTexture.h"
#include "Kismet/KismetRenderingLibrary.h"


// Sets default values for this component's properties
UBakeTexture::UBakeTexture()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	RenderTarget = nullptr;
	Material = nullptr;

	isBaked = true;
}


// Called when the game starts
void UBakeTexture::BeginPlay()
{
	Super::BeginPlay();

	if (RenderTarget && Material) {
		isBaked = false;
	}

}


// Called every frame
void UBakeTexture::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	if (!isBaked) {
		UKismetRenderingLibrary::DrawMaterialToRenderTarget(GetWorld(), RenderTarget, Material);
	}
}
