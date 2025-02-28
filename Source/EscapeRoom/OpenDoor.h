// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Engine/TriggerVolume.h"
#include "OpenDoor.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class ESCAPEROOM_API UOpenDoor : public UActorComponent
{
	GENERATED_BODY()

public:	
		// Sets default values for this component's properties
		UOpenDoor();
		virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

protected:
		// Called when the game starts
		virtual void BeginPlay() override;

		void OpenDoor();
		void CloseDoor();

private:
		UPROPERTY(VisibleAnywhere)
		float OpenAngle = 90.0f;

		UPROPERTY(VisibleAnywhere)
		float CloseAngle = 00.0f;

		UPROPERTY(EditAnywhere)
		ATriggerVolume* PressurePlate;

		UPROPERTY(EditAnywhere)
		float DoorCloseDelay = 0.5f;

		float LastDoorOpenTime;

		AActor* ActorThatOpens;
		AActor* Owner;
};
