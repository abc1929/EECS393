#include "NativizedAssets.h"
#include "BP_LightStudio__pf1934637403.h"
#include "GeneratedCodeHelpers.h"
#include "Runtime/Engine/Classes/Components/DirectionalLightComponent.h"
#include "Runtime/Engine/Classes/Atmosphere/AtmosphericFogComponent.h"
#include "Runtime/Engine/Classes/Engine/SimpleConstructionScript.h"
#include "Runtime/Engine/Classes/Engine/SCS_Node.h"
#include "Runtime/Engine/Classes/Components/SceneComponent.h"
#include "Runtime/Engine/Classes/Components/StaticMeshComponent.h"
#include "Runtime/Engine/Classes/Engine/StaticMesh.h"
#include "Runtime/Engine/Classes/Materials/Material.h"
#include "Runtime/Engine/Classes/Components/ExponentialHeightFogComponent.h"
#include "Runtime/Engine/Classes/Components/SkyLightComponent.h"
#include "Runtime/Engine/Classes/Components/ActorComponent.h"
#include "Runtime/Engine/Classes/Engine/EngineTypes.h"
#include "Runtime/Engine/Classes/Engine/EngineBaseTypes.h"
#include "Runtime/Engine/Classes/EdGraph/EdGraphPin.h"
#include "Runtime/Engine/Classes/Engine/AssetUserData.h"
#include "Runtime/Engine/Classes/Interfaces/Interface_AssetUserData.h"
#include "Runtime/Engine/Classes/GameFramework/PhysicsVolume.h"
#include "Runtime/Engine/Classes/GameFramework/Volume.h"
#include "Runtime/Engine/Classes/Engine/Brush.h"
#include "Runtime/Engine/Classes/Components/BrushComponent.h"
#include "Runtime/Engine/Classes/Components/PrimitiveComponent.h"
#include "Runtime/Engine/Classes/GameFramework/Pawn.h"
#include "Runtime/Engine/Classes/GameFramework/Controller.h"
#include "Runtime/Engine/Classes/GameFramework/PlayerController.h"
#include "Runtime/Engine/Classes/GameFramework/TouchInterface.h"
#include "Runtime/InputCore/Classes/InputCoreTypes.h"
#include "Runtime/Engine/Classes/Engine/Texture2D.h"
#include "Runtime/Engine/Classes/Engine/Texture.h"
#include "Runtime/Engine/Classes/GameFramework/OnlineReplStructs.h"
#include "Runtime/Engine/Classes/Camera/CameraTypes.h"
#include "Runtime/Engine/Classes/Camera/CameraAnim.h"
#include "Runtime/Engine/Classes/Matinee/InterpGroup.h"
#include "Runtime/Engine/Classes/Matinee/InterpTrack.h"
#include "Runtime/Engine/Classes/Matinee/InterpTrackInst.h"
#include "Runtime/Engine/Classes/Camera/CameraShake.h"
#include "Runtime/Engine/Classes/Engine/Scene.h"
#include "Runtime/Engine/Classes/Engine/TextureCube.h"
#include "Runtime/Engine/Classes/Camera/CameraAnimInst.h"
#include "Runtime/Engine/Classes/Matinee/InterpTrackInstMove.h"
#include "Runtime/Engine/Classes/Matinee/InterpTrackMove.h"
#include "Runtime/Engine/Classes/Matinee/InterpGroupInst.h"
#include "Runtime/Engine/Classes/Camera/PlayerCameraManager.h"
#include "Runtime/Engine/Classes/Particles/EmitterCameraLensEffectBase.h"
#include "Runtime/Engine/Classes/Particles/Emitter.h"
#include "Runtime/Engine/Classes/PhysicalMaterials/PhysicalMaterial.h"
#include "Runtime/Engine/Classes/Vehicles/TireType.h"
#include "Runtime/Engine/Classes/Engine/DataAsset.h"
#include "Runtime/Engine/Classes/PhysicalMaterials/PhysicalMaterialPropertyBase.h"
#include "Runtime/Engine/Classes/PhysicsEngine/PhysicsSettingsEnums.h"
#include "Runtime/Engine/Classes/Particles/ParticleSystemComponent.h"
#include "Runtime/Engine/Classes/Materials/MaterialInterface.h"
#include "Runtime/Engine/Classes/Engine/SubsurfaceProfile.h"
#include "Runtime/Engine/Classes/Materials/MaterialExpression.h"
#include "Runtime/Engine/Classes/Engine/BlendableInterface.h"
#include "Runtime/Engine/Public/ParticleHelper.h"
#include "Runtime/Engine/Classes/Components/SkeletalMeshComponent.h"
#include "Runtime/Engine/Classes/Components/SkinnedMeshComponent.h"
#include "Runtime/Engine/Classes/Components/MeshComponent.h"
#include "Runtime/Engine/Classes/Engine/SkeletalMesh.h"
#include "Runtime/Engine/Classes/PhysicsEngine/PhysicsAsset.h"
#include "Runtime/Engine/Classes/PhysicsEngine/BodySetup.h"
#include "Runtime/Engine/Classes/PhysicsEngine/BodyInstance.h"
#include "Runtime/Engine/Classes/PhysicsEngine/BodySetupEnums.h"
#include "Runtime/Engine/Classes/PhysicsEngine/AggregateGeom.h"
#include "Runtime/Engine/Classes/PhysicsEngine/ConvexElem.h"
#include "Runtime/Engine/Classes/PhysicsEngine/ShapeElem.h"
#include "Runtime/Engine/Classes/PhysicsEngine/SphylElem.h"
#include "Runtime/Engine/Classes/PhysicsEngine/BoxElem.h"
#include "Runtime/Engine/Classes/PhysicsEngine/SphereElem.h"
#include "Runtime/Engine/Classes/Animation/Skeleton.h"
#include "Runtime/Engine/Classes/Animation/BlendProfile.h"
#include "Runtime/Engine/Classes/Animation/SmartName.h"
#include "Runtime/Engine/Classes/Engine/SkeletalMeshSocket.h"
#include "Runtime/Engine/Classes/Interfaces/Interface_CollisionDataProvider.h"
#include "Runtime/Engine/Classes/Animation/AnimInstance.h"
#include "Runtime/Engine/Classes/Animation/AnimationAsset.h"
#include "Runtime/Engine/Classes/Animation/AnimMetaData.h"
#include "Runtime/Engine/Classes/Animation/AnimSequenceBase.h"
#include "Runtime/Engine/Public/Animation/AnimCurveTypes.h"
#include "Runtime/Engine/Classes/Curves/RichCurve.h"
#include "Runtime/Engine/Classes/Curves/IndexedCurve.h"
#include "Runtime/Engine/Classes/Curves/KeyHandle.h"
#include "Runtime/Engine/Public/Animation/AnimTypes.h"
#include "Runtime/Engine/Classes/Animation/AnimLinkableElement.h"
#include "Runtime/Engine/Classes/Animation/AnimMontage.h"
#include "Runtime/Engine/Classes/Animation/AnimCompositeBase.h"
#include "Runtime/Engine/Public/AlphaBlend.h"
#include "Runtime/Engine/Classes/Curves/CurveFloat.h"
#include "Runtime/Engine/Classes/Curves/CurveBase.h"
#include "Runtime/Engine/Classes/Animation/AnimNotifies/AnimNotifyState.h"
#include "Runtime/Engine/Classes/Animation/AnimNotifies/AnimNotify.h"
#include "Runtime/Engine/Classes/Particles/ParticleSystem.h"
#include "Runtime/Engine/Classes/Particles/ParticleEmitter.h"
#include "Runtime/Engine/Classes/Materials/MaterialInstanceDynamic.h"
#include "Runtime/Engine/Classes/Materials/MaterialInstance.h"
#include "Runtime/Engine/Classes/Materials/MaterialInstanceBasePropertyOverrides.h"
#include "Runtime/Engine/Classes/Engine/Font.h"
#include "Runtime/SlateCore/Public/Fonts/CompositeFont.h"
#include "Runtime/SlateCore/Public/Fonts/FontBulkData.h"
#include "Runtime/Engine/Classes/Engine/FontImportOptions.h"
#include "Runtime/SlateCore/Public/Fonts/FontProviderInterface.h"
#include "Runtime/Engine/Classes/Camera/CameraModifier.h"
#include "Runtime/Engine/Classes/Camera/CameraActor.h"
#include "Runtime/Engine/Classes/Camera/CameraComponent.h"
#include "Runtime/Engine/Classes/Camera/CameraModifier_CameraShake.h"
#include "Runtime/Engine/Classes/GameFramework/PlayerState.h"
#include "Runtime/Engine/Classes/GameFramework/Info.h"
#include "Runtime/Engine/Classes/GameFramework/LocalMessage.h"
#include "Runtime/Engine/Classes/GameFramework/EngineMessage.h"
#include "Runtime/Engine/Classes/GameFramework/ForceFeedbackEffect.h"
#include "Runtime/Engine/Classes/Sound/SoundBase.h"
#include "Runtime/Engine/Classes/Sound/SoundAttenuation.h"
#include "Runtime/Engine/Classes/Sound/SoundConcurrency.h"
#include "Runtime/Engine/Classes/Sound/SoundClass.h"
#include "Runtime/Engine/Classes/Sound/SoundMix.h"
#include "Runtime/Engine/Classes/GameFramework/HUD.h"
#include "Runtime/Engine/Classes/GameFramework/DebugTextInfo.h"
#include "Runtime/Engine/Classes/Engine/Canvas.h"
#include "Runtime/Engine/Classes/Debug/ReporterGraph.h"
#include "Runtime/Engine/Classes/Debug/ReporterBase.h"
#include "Runtime/Engine/Classes/Engine/NetSerialization.h"
#include "Runtime/Engine/Classes/Components/InputComponent.h"
#include "Runtime/Engine/Classes/GameFramework/SpectatorPawn.h"
#include "Runtime/Engine/Classes/GameFramework/DefaultPawn.h"
#include "Runtime/Engine/Classes/Components/SphereComponent.h"
#include "Runtime/Engine/Classes/Components/ShapeComponent.h"
#include "Runtime/Engine/Classes/AI/Navigation/NavAreas/NavArea.h"
#include "Runtime/Engine/Classes/AI/Navigation/NavigationTypes.h"
#include "Runtime/Engine/Classes/AI/Navigation/NavAreas/NavArea_Obstacle.h"
#include "Runtime/Engine/Classes/GameFramework/PawnMovementComponent.h"
#include "Runtime/Engine/Classes/GameFramework/NavMovementComponent.h"
#include "Runtime/Engine/Classes/GameFramework/MovementComponent.h"
#include "Runtime/Engine/Classes/AI/Navigation/NavigationData.h"
#include "Runtime/Engine/Classes/AI/Navigation/RecastNavMesh.h"
#include "Runtime/Engine/Classes/GameFramework/FloatingPawnMovement.h"
#include "Runtime/AIModule/Classes/AIController.h"
#include "Runtime/GameplayTasks/Classes/GameplayTaskResource.h"
#include "Runtime/AIModule/Classes/Perception/AIPerceptionComponent.h"
#include "Runtime/AIModule/Classes/Perception/AIPerceptionTypes.h"
#include "Runtime/AIModule/Classes/Perception/AISense.h"
#include "Runtime/AIModule/Classes/Perception/AIPerceptionSystem.h"
#include "Runtime/AIModule/Classes/Perception/AISenseEvent.h"
#include "Runtime/AIModule/Classes/Perception/AISenseConfig.h"
#include "Runtime/AIModule/Classes/Navigation/PathFollowingComponent.h"
#include "Runtime/AIModule/Classes/AIResourceInterface.h"
#include "Runtime/Engine/Classes/AI/Navigation/NavFilters/NavigationQueryFilter.h"
#include "Runtime/GameplayTasks/Classes/GameplayTask.h"
#include "Runtime/AIModule/Classes/BehaviorTree/BlackboardData.h"
#include "Runtime/AIModule/Classes/BehaviorTree/BlackboardComponent.h"
#include "Runtime/AIModule/Classes/BehaviorTree/Blackboard/BlackboardKeyType.h"
#include "Runtime/AIModule/Classes/BrainComponent.h"
#include "Runtime/AIModule/Classes/BehaviorTree/BehaviorTree.h"
#include "Runtime/AIModule/Classes/BehaviorTree/BTCompositeNode.h"
#include "Runtime/AIModule/Classes/BehaviorTree/BTNode.h"
#include "Runtime/GameplayTasks/Classes/GameplayTaskOwnerInterface.h"
#include "Runtime/AIModule/Classes/BehaviorTree/BTService.h"
#include "Runtime/AIModule/Classes/BehaviorTree/BTAuxiliaryNode.h"
#include "Runtime/AIModule/Classes/BehaviorTree/BTDecorator.h"
#include "Runtime/AIModule/Classes/BehaviorTree/BehaviorTreeTypes.h"
#include "Runtime/AIModule/Classes/BehaviorTree/BTTaskNode.h"
#include "Runtime/AIModule/Classes/AITypes.h"
#include "Runtime/GameplayTasks/Classes/GameplayTasksComponent.h"
#include "Runtime/AIModule/Classes/Actions/PawnActionsComponent.h"
#include "Runtime/AIModule/Classes/Actions/PawnAction.h"
#include "Runtime/AIModule/Classes/Perception/AIPerceptionListenerInterface.h"
#include "Runtime/AIModule/Classes/GenericTeamAgentInterface.h"
#include "Runtime/Engine/Public/VisualLogger/VisualLoggerDebugSnapshotInterface.h"
#include "Runtime/Engine/Classes/GameFramework/SpectatorPawnMovement.h"
#include "Runtime/Engine/Classes/Engine/LatentActionManager.h"
#include "Runtime/Engine/Classes/Haptics/HapticFeedbackEffect_Base.h"
#include "Runtime/Engine/Classes/Engine/NetConnection.h"
#include "Runtime/Engine/Classes/Engine/Player.h"
#include "Runtime/Engine/Classes/Engine/Channel.h"
#include "Runtime/Engine/Classes/Engine/NetDriver.h"
#include "Runtime/Engine/Classes/Engine/World.h"
#include "Runtime/Engine/Classes/Engine/ChildConnection.h"
#include "Runtime/Engine/Classes/GameFramework/PlayerInput.h"
#include "Runtime/Engine/Classes/GameFramework/CheatManager.h"
#include "Runtime/Engine/Classes/Engine/DebugCameraController.h"
#include "Runtime/Engine/Classes/Components/DrawFrustumComponent.h"
#include "Runtime/Engine/Classes/Matinee/InterpTrackInstDirector.h"
#include "Runtime/Engine/Classes/GameFramework/DamageType.h"
#include "Runtime/Engine/Classes/GameFramework/Character.h"
#include "Runtime/Engine/Classes/GameFramework/CharacterMovementComponent.h"
#include "Runtime/Engine/Classes/GameFramework/RootMotionSource.h"
#include "Runtime/Engine/Classes/AI/Navigation/NavigationAvoidanceTypes.h"
#include "Runtime/Engine/Public/AI/RVOAvoidanceInterface.h"
#include "Runtime/Engine/Classes/Interfaces/NetworkPredictionInterface.h"
#include "Runtime/Engine/Classes/Components/CapsuleComponent.h"
#include "Runtime/Engine/Classes/AI/Navigation/NavAgentInterface.h"
#include "Runtime/Engine/Classes/AI/Navigation/NavRelevantInterface.h"
#include "Runtime/Engine/Classes/Components/ChildActorComponent.h"
#include "BP_LightStudio__pf1934637403.h"
#include "Runtime/Engine/Classes/Curves/CurveLinearColor.h"
#include "Runtime/Engine/Classes/Components/LightComponent.h"
#include "Runtime/Engine/Classes/Components/LightComponentBase.h"
#include "Runtime/Engine/Classes/Engine/TextureLightProfile.h"
#include "Runtime/Engine/Classes/Kismet/KismetMaterialLibrary.h"
#include "Runtime/Engine/Classes/Kismet/KismetMathLibrary.h"
#include "Runtime/Engine/Classes/Materials/MaterialInstanceConstant.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
ABP_LightStudio_C__pf1934637403::ABP_LightStudio_C__pf1934637403(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{
	if(HasAnyFlags(RF_ClassDefaultObject) && (ABP_LightStudio_C__pf1934637403::StaticClass() == GetClass()))
	{
		ABP_LightStudio_C__pf1934637403::__CustomDynamicClassInitialization(CastChecked<UDynamicClass>(GetClass()));
	}
	
	bpv__Scene1__pf = CreateDefaultSubobject<USceneComponent>(TEXT("Scene1"));
	bpv__Skybox__pf = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Skybox"));
	bpv__PrevisArrow__pf = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("PrevisArrow"));
	bpv__ExponentialHeightFog1__pf = CreateDefaultSubobject<UExponentialHeightFogComponent>(TEXT("ExponentialHeightFog1"));
	bpv__SkyLight1__pf = CreateDefaultSubobject<USkyLightComponent>(TEXT("SkyLight1"));
	RootComponent = bpv__Scene1__pf;
	bpv__Scene1__pf->CreationMethod = EComponentCreationMethod::Native;
	bpv__Scene1__pf->Mobility = EComponentMobility::Type::Static;
	bpv__Skybox__pf->CreationMethod = EComponentCreationMethod::Native;
	bpv__Skybox__pf->AttachToComponent(bpv__Scene1__pf, FAttachmentTransformRules::KeepRelativeTransform );
	bpv__Skybox__pf->BodyInstance.SetCollisionProfileName(FName(TEXT("Custom")));
	static TWeakObjectPtr<UProperty> __Local__1{};
	const UProperty* __Local__0 = __Local__1.Get();
	if (nullptr == __Local__0)
	{
		__Local__0 = (FBodyInstance::StaticStruct())->FindPropertyByName(FName(TEXT("CollisionResponses")));
		check(__Local__0);
		__Local__1 = __Local__0;
	}
	auto& __Local__2 = (*(__Local__0->ContainerPtrToValuePtr<FCollisionResponse >(&(bpv__Skybox__pf->BodyInstance), 0)));
	static TWeakObjectPtr<UProperty> __Local__4{};
	const UProperty* __Local__3 = __Local__4.Get();
	if (nullptr == __Local__3)
	{
		__Local__3 = (FCollisionResponse::StaticStruct())->FindPropertyByName(FName(TEXT("ResponseArray")));
		check(__Local__3);
		__Local__4 = __Local__3;
	}
	auto& __Local__5 = (*(__Local__3->ContainerPtrToValuePtr<TArray<FResponseChannel> >(&(__Local__2), 0)));
	__Local__5 = TArray<FResponseChannel> ();
	__Local__5.AddUninitialized(8);
	FResponseChannel::StaticStruct()->InitializeStruct(__Local__5.GetData(), 8);
	auto& __Local__6 = __Local__5[0];
	__Local__6.Channel = FName(TEXT("WorldStatic"));
	__Local__6.Response = ECollisionResponse::ECR_Ignore;
	auto& __Local__7 = __Local__5[1];
	__Local__7.Channel = FName(TEXT("WorldDynamic"));
	__Local__7.Response = ECollisionResponse::ECR_Ignore;
	auto& __Local__8 = __Local__5[2];
	__Local__8.Channel = FName(TEXT("Pawn"));
	__Local__8.Response = ECollisionResponse::ECR_Ignore;
	auto& __Local__9 = __Local__5[3];
	__Local__9.Channel = FName(TEXT("Visibility"));
	__Local__9.Response = ECollisionResponse::ECR_Ignore;
	auto& __Local__10 = __Local__5[4];
	__Local__10.Channel = FName(TEXT("Camera"));
	__Local__10.Response = ECollisionResponse::ECR_Ignore;
	auto& __Local__11 = __Local__5[5];
	__Local__11.Channel = FName(TEXT("PhysicsBody"));
	__Local__11.Response = ECollisionResponse::ECR_Ignore;
	auto& __Local__12 = __Local__5[6];
	__Local__12.Channel = FName(TEXT("Vehicle"));
	__Local__12.Response = ECollisionResponse::ECR_Ignore;
	auto& __Local__13 = __Local__5[7];
	__Local__13.Channel = FName(TEXT("Destructible"));
	__Local__13.Response = ECollisionResponse::ECR_Ignore;
	bpv__Skybox__pf->BodyInstance.bAutoWeld = false;
	static TWeakObjectPtr<UProperty> __Local__15{};
	const UProperty* __Local__14 = __Local__15.Get();
	if (nullptr == __Local__14)
	{
		__Local__14 = (FBodyInstance::StaticStruct())->FindPropertyByName(FName(TEXT("CollisionEnabled")));
		check(__Local__14);
		__Local__15 = __Local__14;
	}
	auto& __Local__16 = (*(__Local__14->ContainerPtrToValuePtr<TEnumAsByte<ECollisionEnabled::Type> >(&(bpv__Skybox__pf->BodyInstance), 0)));
	__Local__16 = ECollisionEnabled::Type::NoCollision;
	bpv__Skybox__pf->StaticMesh = CastChecked<UStaticMesh>(CastChecked<UDynamicClass>(ABP_LightStudio_C__pf1934637403::StaticClass())->UsedAssets[0], ECastCheckedType::NullAllowed);
	bpv__Skybox__pf->OverrideMaterials = TArray<UMaterialInterface*> ();
	bpv__Skybox__pf->OverrideMaterials.Reserve(1);
	bpv__Skybox__pf->OverrideMaterials.Add(CastChecked<UMaterialInterface>(CastChecked<UDynamicClass>(ABP_LightStudio_C__pf1934637403::StaticClass())->UsedAssets[1], ECastCheckedType::NullAllowed));
	bpv__Skybox__pf->CastShadow = false;
	bpv__Skybox__pf->bCastDynamicShadow = false;
	bpv__Skybox__pf->bCastStaticShadow = false;
	bpv__Skybox__pf->RelativeScale3D = FVector(50000.000000, 50000.000000, 50000.000000);
	bpv__Skybox__pf->Mobility = EComponentMobility::Type::Static;
	if(!bpv__Skybox__pf->IsTemplate())
	{
		bpv__Skybox__pf->BodyInstance.FixupData(bpv__Skybox__pf);
	}
	bpv__PrevisArrow__pf->CreationMethod = EComponentCreationMethod::Native;
	bpv__PrevisArrow__pf->AttachToComponent(bpv__Scene1__pf, FAttachmentTransformRules::KeepRelativeTransform );
	bpv__PrevisArrow__pf->BodyInstance.SetCollisionProfileName(FName(TEXT("Custom")));
	auto& __Local__17 = (*(__Local__0->ContainerPtrToValuePtr<FCollisionResponse >(&(bpv__PrevisArrow__pf->BodyInstance), 0)));
	auto& __Local__18 = (*(__Local__3->ContainerPtrToValuePtr<TArray<FResponseChannel> >(&(__Local__17), 0)));
	__Local__18 = TArray<FResponseChannel> ();
	__Local__18.AddUninitialized(8);
	FResponseChannel::StaticStruct()->InitializeStruct(__Local__18.GetData(), 8);
	auto& __Local__19 = __Local__18[0];
	__Local__19.Channel = FName(TEXT("WorldStatic"));
	__Local__19.Response = ECollisionResponse::ECR_Ignore;
	auto& __Local__20 = __Local__18[1];
	__Local__20.Channel = FName(TEXT("WorldDynamic"));
	__Local__20.Response = ECollisionResponse::ECR_Ignore;
	auto& __Local__21 = __Local__18[2];
	__Local__21.Channel = FName(TEXT("Pawn"));
	__Local__21.Response = ECollisionResponse::ECR_Ignore;
	auto& __Local__22 = __Local__18[3];
	__Local__22.Channel = FName(TEXT("Visibility"));
	__Local__22.Response = ECollisionResponse::ECR_Ignore;
	auto& __Local__23 = __Local__18[4];
	__Local__23.Channel = FName(TEXT("Camera"));
	__Local__23.Response = ECollisionResponse::ECR_Ignore;
	auto& __Local__24 = __Local__18[5];
	__Local__24.Channel = FName(TEXT("PhysicsBody"));
	__Local__24.Response = ECollisionResponse::ECR_Ignore;
	auto& __Local__25 = __Local__18[6];
	__Local__25.Channel = FName(TEXT("Vehicle"));
	__Local__25.Response = ECollisionResponse::ECR_Ignore;
	auto& __Local__26 = __Local__18[7];
	__Local__26.Channel = FName(TEXT("Destructible"));
	__Local__26.Response = ECollisionResponse::ECR_Ignore;
	bpv__PrevisArrow__pf->BodyInstance.bAutoWeld = false;
	auto& __Local__27 = (*(__Local__14->ContainerPtrToValuePtr<TEnumAsByte<ECollisionEnabled::Type> >(&(bpv__PrevisArrow__pf->BodyInstance), 0)));
	__Local__27 = ECollisionEnabled::Type::NoCollision;
	bpv__PrevisArrow__pf->StaticMesh = CastChecked<UStaticMesh>(CastChecked<UDynamicClass>(ABP_LightStudio_C__pf1934637403::StaticClass())->UsedAssets[2], ECastCheckedType::NullAllowed);
	bpv__PrevisArrow__pf->OverrideMaterials = TArray<UMaterialInterface*> ();
	bpv__PrevisArrow__pf->OverrideMaterials.Reserve(1);
	bpv__PrevisArrow__pf->OverrideMaterials.Add(CastChecked<UMaterialInterface>(CastChecked<UDynamicClass>(ABP_LightStudio_C__pf1934637403::StaticClass())->UsedAssets[3], ECastCheckedType::NullAllowed));
	bpv__PrevisArrow__pf->CastShadow = false;
	bpv__PrevisArrow__pf->bCastDynamicShadow = false;
	bpv__PrevisArrow__pf->bCastStaticShadow = false;
	bpv__PrevisArrow__pf->bHiddenInGame = true;
	bpv__PrevisArrow__pf->RelativeScale3D = FVector(0.500000, 0.500000, 0.500000);
	if(!bpv__PrevisArrow__pf->IsTemplate())
	{
		bpv__PrevisArrow__pf->BodyInstance.FixupData(bpv__PrevisArrow__pf);
	}
	bpv__ExponentialHeightFog1__pf->CreationMethod = EComponentCreationMethod::Native;
	bpv__ExponentialHeightFog1__pf->AttachToComponent(bpv__Scene1__pf, FAttachmentTransformRules::KeepRelativeTransform );
	bpv__ExponentialHeightFog1__pf->DirectionalInscatteringColor = FLinearColor(1.000000, 0.000000, 0.633525, 1.000000);
	bpv__SkyLight1__pf->CreationMethod = EComponentCreationMethod::Native;
	bpv__SkyLight1__pf->AttachToComponent(bpv__Scene1__pf, FAttachmentTransformRules::KeepRelativeTransform );
	bpv__SkyLight1__pf->bLowerHemisphereIsBlack = false;
	bpv__SkyLight1__pf->LightGuid = FGuid(0xE55669EE, 0x447068FB, 0x1561ABB7, 0xEED54DE7);
	bpv__GlobalBrightness__pf = 1.000000f;
	bpv__Use_HDRI__pf = false;
	bpv__UseSunLight__pf = true;
	bpv__SunBrightness__pf = 1.000000f;
	bpv__SunTint__pf = FLinearColor(1.000000, 1.000000, 1.000000, 1.000000);
	bpv__StationaryLightForSun__pf = false;
	bpv__SunDirectionalLight__pf = nullptr;
	bpv__UseAtmosphere__pf = true;
	bpv__AtmosphereBrightness__pf = 1.000000f;
	bpv__AtmosphereTint__pf = FLinearColor(1.000000, 1.000000, 1.000000, 1.000000);
	bpv__PrevisArrowMaterial__pf = nullptr;
	bpv__LightColor__pf = FLinearColor(0.000000, 0.000000, 0.000000, 0.000000);
	bpv__SunColorCurve__pf = CastChecked<UCurveLinearColor>(CastChecked<UDynamicClass>(ABP_LightStudio_C__pf1934637403::StaticClass())->UsedAssets[4], ECastCheckedType::NullAllowed);
	bpv__OverrideSunColor__pf = false;
	bpv__AtmosphereDensityMultiplier__pf = 1.000000f;
	bpv__AtmosphereAltitude__pf = 100000.000000f;
	bpv__DisableSunDisk__pf = false;
	bpv__UseFog__pf = false;
	bpv__FogBrightness__pf = 1.000000f;
	bpv__FogTint__pf = FLinearColor(0.500000, 0.500000, 0.500000, 1.000000);
	bpv__FogAltitude__pf = 0.000000f;
	bpv__FogMaxOpacity__pf = 1.000000f;
	bpv__FogHeightFalloff__pf = 0.200000f;
	bpv__FogDensity__pf = 0.020000f;
	bpv__FogBrightnessCurve__pf = CastChecked<UCurveFloat>(CastChecked<UDynamicClass>(ABP_LightStudio_C__pf1934637403::StaticClass())->UsedAssets[5], ECastCheckedType::NullAllowed);
	bpv__FogStartDistance__pf = 3000.000000f;
	bpv__DisableGroundScattering__pf = false;
	bpv__AtmosphereDistanceScale__pf = 1.000000f;
	bpv__SkyboxMaterial__pf = nullptr;
	bpv__HDRI_Brightness__pf = 1.000000f;
	bpv__HDRI_Contrast__pf = 1.000000f;
	bpv__HDRI_Tint__pf = FLinearColor(1.000000, 1.000000, 1.000000, 1.000000);
	bpv__HDRI_Cubemap__pf = CastChecked<UTexture>(CastChecked<UDynamicClass>(ABP_LightStudio_C__pf1934637403::StaticClass())->UsedAssets[6], ECastCheckedType::NullAllowed);
	bpv__HDRI_Rotation__pf = 0.000000f;
	bpv__AtmosphereOpacityHorizon__pf = 1.000000f;
	bpv__AtmosphereOpacityZenith__pf = 1.000000f;
	bpv__HighDensityAtmosphere__pf = true;
	bpv__AtmosphericFog__pf = nullptr;
	bpv__UseSkylight__pf = true;
	bpv__Shadowdistance__pf = 10000.000000f;
	bpv__LightShaftBloom__pf = false;
	bpv__LightShaftOcclusion__pf = false;
	bpv__OcclusionMaskDarkness__pf = 0.050000f;
	bpv__BloomScale__pf = 0.200000f;
	bpv__BloomThreshold__pf = 0.000000f;
	bpv__BloomTint__pf = FColor(255, 255, 255, 0);
	bpv__AtmosphereFogMultiplier__pf = 1.000000f;
	bpv__AtmosphereDensityHeight__pf = 0.500000f;
	bpv__AtmosphereMaxScatteringOrder__pf = 4;
	bpv__AtmosphereAltitudeSampleNumber__pf = 2;
	bpv__LightFunctionMaterial__pf = nullptr;
	bpv__MIC_Black__pf = CastChecked<UMaterialInstance>(CastChecked<UDynamicClass>(ABP_LightStudio_C__pf1934637403::StaticClass())->UsedAssets[7], ECastCheckedType::NullAllowed);
	bpv__MIC_HDRI__pf = CastChecked<UMaterialInstance>(CastChecked<UDynamicClass>(ABP_LightStudio_C__pf1934637403::StaticClass())->UsedAssets[8], ECastCheckedType::NullAllowed);
}
void ABP_LightStudio_C__pf1934637403::PostLoadSubobjects(FObjectInstancingGraph* OuterInstanceGraph)
{
	Super::PostLoadSubobjects(OuterInstanceGraph);
	if(bpv__Scene1__pf)
	{
		bpv__Scene1__pf->CreationMethod = EComponentCreationMethod::Native;
	}
	if(bpv__Skybox__pf)
	{
		bpv__Skybox__pf->CreationMethod = EComponentCreationMethod::Native;
	}
	if(bpv__PrevisArrow__pf)
	{
		bpv__PrevisArrow__pf->CreationMethod = EComponentCreationMethod::Native;
	}
	if(bpv__ExponentialHeightFog1__pf)
	{
		bpv__ExponentialHeightFog1__pf->CreationMethod = EComponentCreationMethod::Native;
	}
	if(bpv__SkyLight1__pf)
	{
		bpv__SkyLight1__pf->CreationMethod = EComponentCreationMethod::Native;
	}
}
void ABP_LightStudio_C__pf1934637403::__CustomDynamicClassInitialization(UDynamicClass* InDynamicClass)
{
	ensure(0 == InDynamicClass->ReferencedConvertedFields.Num());
	ensure(0 == InDynamicClass->MiscConvertedSubobjects.Num());
	ensure(0 == InDynamicClass->DynamicBindingObjects.Num());
	ensure(0 == InDynamicClass->ComponentTemplates.Num());
	ensure(0 == InDynamicClass->Timelines.Num());
	ensure(nullptr == InDynamicClass->AnimClassImplementation);
	InDynamicClass->AssembleReferenceTokenStream();
	FConvertedBlueprintsDependencies::FillUsedAssetsInDynamicClass(InDynamicClass, &__StaticDependencies_DirectlyUsedAssets);
	auto __Local__28 = NewObject<UDirectionalLightComponent>(InDynamicClass, UDirectionalLightComponent::StaticClass(), TEXT("DirectionalLightComponent_3656"));
	InDynamicClass->ComponentTemplates.Add(__Local__28);
	auto __Local__29 = NewObject<UDirectionalLightComponent>(InDynamicClass, UDirectionalLightComponent::StaticClass(), TEXT("DirectionalLightComponent_3657"));
	InDynamicClass->ComponentTemplates.Add(__Local__29);
	auto __Local__30 = NewObject<UAtmosphericFogComponent>(InDynamicClass, UAtmosphericFogComponent::StaticClass(), TEXT("AtmosphericFogComponent_73"));
	InDynamicClass->ComponentTemplates.Add(__Local__30);
	auto __Local__31 = NewObject<UAtmosphericFogComponent>(InDynamicClass, UAtmosphericFogComponent::StaticClass(), TEXT("AtmosphericFogComponent_74"));
	InDynamicClass->ComponentTemplates.Add(__Local__31);
	auto __Local__32 = NewObject<UAtmosphericFogComponent>(InDynamicClass, UAtmosphericFogComponent::StaticClass(), TEXT("AtmosphericFogComponent_0"));
	InDynamicClass->ComponentTemplates.Add(__Local__32);
	auto __Local__33 = NewObject<UAtmosphericFogComponent>(InDynamicClass, UAtmosphericFogComponent::StaticClass(), TEXT("AtmosphericFogComponent_1"));
	InDynamicClass->ComponentTemplates.Add(__Local__33);
	auto __Local__34 = NewObject<UDirectionalLightComponent>(InDynamicClass, UDirectionalLightComponent::StaticClass(), TEXT("DirectionalLightComponent_0"));
	InDynamicClass->ComponentTemplates.Add(__Local__34);
	auto __Local__35 = NewObject<UDirectionalLightComponent>(InDynamicClass, UDirectionalLightComponent::StaticClass(), TEXT("DirectionalLightComponent_1"));
	InDynamicClass->ComponentTemplates.Add(__Local__35);
	__Local__28->DynamicShadowDistanceMovableLight = 200000.000000f;
	__Local__28->CascadeDistributionExponent = 4.000000f;
	__Local__28->ShadowBias = 0.400000f;
	__Local__28->bAffectDynamicIndirectLighting = true;
	__Local__28->LightGuid = FGuid(0xFFA0753B, 0x4B6BF48A, 0x0E712189, 0x220BD6EC);
	__Local__28->Intensity = 3.141593f;
	__Local__28->bPrecomputedLightingIsValid = false;
	__Local__29->ShadowBias = 0.400000f;
	__Local__29->bAffectDynamicIndirectLighting = true;
	__Local__29->LightGuid = FGuid(0xDB7D24EF, 0x43DAC985, 0x4CC20582, 0x4970E231);
	__Local__29->Intensity = 3.141593f;
	__Local__29->bPrecomputedLightingIsValid = false;
	__Local__29->Mobility = EComponentMobility::Type::Stationary;
	static TWeakObjectPtr<UProperty> __Local__37{};
	const UProperty* __Local__36 = __Local__37.Get();
	if (nullptr == __Local__36)
	{
		__Local__36 = (UAtmosphericFogComponent::StaticClass())->FindPropertyByName(FName(TEXT("PrecomputeParams")));
		check(__Local__36);
		__Local__37 = __Local__36;
	}
	auto& __Local__38 = (*(__Local__36->ContainerPtrToValuePtr<FAtmospherePrecomputeParameters >((__Local__30), 0)));
	__Local__38.DensityHeight = 0.800000f;
	auto& __Local__39 = (*(__Local__36->ContainerPtrToValuePtr<FAtmospherePrecomputeParameters >((__Local__33), 0)));
	__Local__39.DensityHeight = 0.800000f;
	__Local__34->ShadowBias = 0.400000f;
	__Local__34->bAffectDynamicIndirectLighting = true;
	__Local__34->LightGuid = FGuid(0xDB7D24EF, 0x43DAC985, 0x4CC20582, 0x4970E231);
	__Local__34->Intensity = 3.141593f;
	__Local__34->bPrecomputedLightingIsValid = false;
	__Local__34->Mobility = EComponentMobility::Type::Stationary;
	__Local__35->DynamicShadowDistanceMovableLight = 200000.000000f;
	__Local__35->CascadeDistributionExponent = 4.000000f;
	__Local__35->ShadowBias = 0.400000f;
	__Local__35->bAffectDynamicIndirectLighting = true;
	__Local__35->LightGuid = FGuid(0xFFA0753B, 0x4B6BF48A, 0x0E712189, 0x220BD6EC);
	__Local__35->Intensity = 3.141593f;
	__Local__35->bPrecomputedLightingIsValid = false;
}
void ABP_LightStudio_C__pf1934637403::bpf__UserConstructionScript__pf()
{
	FVector bpv__CallFunc_MakeVector_ReturnValue__pf(EForceInit::ForceInit);
	FRotator bpv__CallFunc_K2_GetComponentRotation_ReturnValue__pf(EForceInit::ForceInit);
	bool bpv_____bool_Variable__pf{};
	float bpv__CallFunc_BreakRotator_Roll__pf{};
	float bpv__CallFunc_BreakRotator_Pitch__pf{};
	float bpv__CallFunc_BreakRotator_Yaw__pf{};
	float bpv__CallFunc_Divide_FloatFloat_ReturnValue__pf{};
	FVector bpv__CallFunc_MakeVector_ReturnValue2__pf(EForceInit::ForceInit);
	FHitResult bpv__CallFunc_K2_SetWorldLocation_SweepHitResult__pf{};
	float bpv__CallFunc_Add_FloatFloat_ReturnValue__pf{};
	float bpv__CallFunc_Multiply_FloatFloat_ReturnValue__pf{};
	FHitResult bpv__CallFunc_K2_SetWorldLocation_SweepHitResult2__pf{};
	float bpv__CallFunc_NormalizedSunAngle_Angle__pf{};
	float bpv__CallFunc_GetFloatValue_ReturnValue__pf{};
	float bpv__CallFunc_Multiply_FloatFloat_ReturnValue2__pf{};
	float bpv__CallFunc_Multiply_FloatFloat_ReturnValue3__pf{};
	FLinearColor bpv__CallFunc_Conv_FloatToLinearColor_ReturnValue__pf(EForceInit::ForceInit);
	FLinearColor bpv__CallFunc_LinearColorLerp_ReturnValue__pf(EForceInit::ForceInit);
	FLinearColor bpv__CallFunc_Multiply_LinearColorLinearColor_ReturnValue__pf(EForceInit::ForceInit);
	FLinearColor bpv__CallFunc_Multiply_LinearColorLinearColor_ReturnValue2__pf(EForceInit::ForceInit);
	float bpv__CallFunc_Multiply_FloatFloat_ReturnValue4__pf{};
	UMaterialInterface* bpv__K2Node_Select_Default__pf{};
	UMaterialInstanceDynamic* bpv__CallFunc_CreateDynamicMaterialInstance_ReturnValue__pf{};
	UMaterialInstanceDynamic* bpv__CallFunc_CreateDynamicMaterialInstance_ReturnValue2__pf{};
	FHitResult bpv__CallFunc_K2_SetWorldRotation_SweepHitResult__pf{};
	float bpv__CallFunc_Multiply_FloatFloat_ReturnValue5__pf{};
	TArray< int32, TInlineAllocator<8> > StateStack;

	int32 CurrentState = 1;
	do
	{
		switch( CurrentState )
		{
		case 1:
			{
				StateStack.Push(47);
				StateStack.Push(40);
				StateStack.Push(36);
				StateStack.Push(22);
				StateStack.Push(11);
			}
		case 2:
			{
				if(IsValid(bpv__Skybox__pf))
				{
					bpv__Skybox__pf->K2_SetWorldRotation(FRotator(0.000000,0.000000,0.000000), false, /*out*/ bpv__CallFunc_K2_SetWorldRotation_SweepHitResult__pf, false);
				}
			}
		case 3:
			{
				bpv_____bool_Variable__pf = bpv__Use_HDRI__pf;
				bpv__CallFunc_CreateDynamicMaterialInstance_ReturnValue__pf = UKismetMaterialLibrary::CreateDynamicMaterialInstance(this, TSwitchValue<bool , UMaterialInterface* >(bpv_____bool_Variable__pf, bpv__K2Node_Select_Default__pf, 2, TSwitchPair<bool , UMaterialInterface* >(false, bpv__MIC_Black__pf), TSwitchPair<bool , UMaterialInterface* >(true, bpv__MIC_HDRI__pf)));
			}
		case 4:
			{
				bpv__SkyboxMaterial__pf = bpv__CallFunc_CreateDynamicMaterialInstance_ReturnValue__pf;
			}
		case 5:
			{
				if(IsValid(bpv__Skybox__pf))
				{
					bpv__Skybox__pf->SetMaterial(0, bpv__SkyboxMaterial__pf);
				}
			}
		case 6:
			{
				bpv__CallFunc_Multiply_FloatFloat_ReturnValue__pf = UKismetMathLibrary::Multiply_FloatFloat(bpv__HDRI_Brightness__pf, bpv__GlobalBrightness__pf);
				if(IsValid(bpv__SkyboxMaterial__pf))
				{
					bpv__SkyboxMaterial__pf->SetScalarParameterValue(FName(TEXT("HDRI_Brightness")), bpv__CallFunc_Multiply_FloatFloat_ReturnValue__pf);
				}
			}
		case 7:
			{
				if(IsValid(bpv__SkyboxMaterial__pf))
				{
					bpv__SkyboxMaterial__pf->SetVectorParameterValue(FName(TEXT("HDRI_Tint")), bpv__HDRI_Tint__pf);
				}
			}
		case 8:
			{
				if(IsValid(bpv__SkyboxMaterial__pf))
				{
					bpv__SkyboxMaterial__pf->SetTextureParameterValue(FName(TEXT("HDRI_Cubemap")), bpv__HDRI_Cubemap__pf);
				}
			}
		case 9:
			{
				if(IsValid(bpv__PrevisArrow__pf))
				{
					bpv__CallFunc_K2_GetComponentRotation_ReturnValue__pf = bpv__PrevisArrow__pf->K2_GetComponentRotation();
				}
				UKismetMathLibrary::BreakRotator(bpv__CallFunc_K2_GetComponentRotation_ReturnValue__pf, /*out*/ bpv__CallFunc_BreakRotator_Roll__pf, /*out*/ bpv__CallFunc_BreakRotator_Pitch__pf, /*out*/ bpv__CallFunc_BreakRotator_Yaw__pf);
				bpv__CallFunc_Divide_FloatFloat_ReturnValue__pf = FCustomThunkTemplates::Divide_FloatFloat(bpv__CallFunc_BreakRotator_Yaw__pf, -360.000000);
				bpv__CallFunc_Add_FloatFloat_ReturnValue__pf = UKismetMathLibrary::Add_FloatFloat(bpv__CallFunc_Divide_FloatFloat_ReturnValue__pf, bpv__HDRI_Rotation__pf);
				if(IsValid(bpv__SkyboxMaterial__pf))
				{
					bpv__SkyboxMaterial__pf->SetScalarParameterValue(FName(TEXT("CubemapRotation")), bpv__CallFunc_Add_FloatFloat_ReturnValue__pf);
				}
			}
		case 10:
			{
				if(IsValid(bpv__SkyboxMaterial__pf))
				{
					bpv__SkyboxMaterial__pf->SetScalarParameterValue(FName(TEXT("HDRI_Contrast")), bpv__HDRI_Contrast__pf);
				}
				CurrentState = (StateStack.Num() > 0) ? StateStack.Pop(/*bAllowShrinking=*/ false) : -1;
				break;
			}
		case 11:
			{
				bpf__AtmosphereDensity__pf();
			}
		case 12:
			{
				if(IsValid(bpv__AtmosphericFog__pf))
				{
					bpv__AtmosphericFog__pf->SetVisibility(bpv__UseAtmosphere__pf, false);
				}
			}
		case 13:
			{
				bpv__CallFunc_MakeVector_ReturnValue2__pf = UKismetMathLibrary::MakeVector(0.000000, 0.000000, bpv__AtmosphereAltitude__pf);
				if(IsValid(bpv__AtmosphericFog__pf))
				{
					bpv__AtmosphericFog__pf->K2_SetWorldLocation(bpv__CallFunc_MakeVector_ReturnValue2__pf, false, /*out*/ bpv__CallFunc_K2_SetWorldLocation_SweepHitResult__pf, false);
				}
			}
		case 14:
			{
				bpv__CallFunc_Multiply_FloatFloat_ReturnValue4__pf = UKismetMathLibrary::Multiply_FloatFloat(bpv__GlobalBrightness__pf, bpv__AtmosphereBrightness__pf);
				if(IsValid(bpv__AtmosphericFog__pf))
				{
					bpv__AtmosphericFog__pf->SetDefaultBrightness(bpv__CallFunc_Multiply_FloatFloat_ReturnValue4__pf);
				}
			}
		case 15:
			{
				if(IsValid(bpv__AtmosphericFog__pf))
				{
					bpv__AtmosphericFog__pf->DisableSunDisk(bpv__DisableSunDisk__pf);
				}
			}
		case 16:
			{
				if(IsValid(bpv__AtmosphericFog__pf))
				{
					bpv__AtmosphericFog__pf->DisableGroundScattering(bpv__DisableGroundScattering__pf);
				}
			}
		case 17:
			{
				if(IsValid(bpv__AtmosphericFog__pf))
				{
					bpv__AtmosphericFog__pf->SetSunMultiplier(bpv__AtmosphereBrightness__pf);
				}
			}
		case 18:
			{
				if(IsValid(bpv__AtmosphericFog__pf))
				{
					bpv__AtmosphericFog__pf->SetDefaultLightColor(bpv__AtmosphereTint__pf);
				}
			}
		case 19:
			{
				if(IsValid(bpv__AtmosphericFog__pf))
				{
					bpv__AtmosphericFog__pf->SetDistanceScale(bpv__AtmosphereDistanceScale__pf);
				}
			}
		case 20:
			{
				if(IsValid(bpv__AtmosphericFog__pf))
				{
					bpv__AtmosphericFog__pf->SetDensityMultiplier(bpv__AtmosphereDensityMultiplier__pf);
				}
			}
		case 21:
			{
				if(IsValid(bpv__AtmosphericFog__pf))
				{
					bpv__AtmosphericFog__pf->SetFogMultiplier(bpv__AtmosphereFogMultiplier__pf);
				}
				CurrentState = (StateStack.Num() > 0) ? StateStack.Pop(/*bAllowShrinking=*/ false) : -1;
				break;
			}
		case 22:
			{
				if (!bpv__UseSunLight__pf)
				{
					CurrentState = (StateStack.Num() > 0) ? StateStack.Pop(/*bAllowShrinking=*/ false) : -1;
					break;
				}
			}
		case 23:
			{
				bpf__SunMobility__pf();
			}
		case 24:
			{
				bpf__CalculateSunColor__pf();
			}
		case 25:
			{
				bpv__CallFunc_Multiply_FloatFloat_ReturnValue5__pf = UKismetMathLibrary::Multiply_FloatFloat(bpv__SunBrightness__pf, bpv__GlobalBrightness__pf);
				if(IsValid(bpv__SunDirectionalLight__pf))
				{
					bpv__SunDirectionalLight__pf->SetIntensity(bpv__CallFunc_Multiply_FloatFloat_ReturnValue5__pf);
				}
			}
		case 26:
			{
				if(IsValid(bpv__SunDirectionalLight__pf))
				{
					bpv__SunDirectionalLight__pf->SetLightColor(bpv__LightColor__pf, true);
				}
			}
		case 27:
			{
				if(IsValid(bpv__SunDirectionalLight__pf))
				{
					bpv__SunDirectionalLight__pf->SetDynamicShadowDistanceMovableLight(bpv__Shadowdistance__pf);
				}
			}
		case 28:
			{
				if(IsValid(bpv__SunDirectionalLight__pf))
				{
					bpv__SunDirectionalLight__pf->SetDynamicShadowDistanceStationaryLight(bpv__Shadowdistance__pf);
				}
			}
		case 29:
			{
				if(IsValid(bpv__SunDirectionalLight__pf))
				{
					bpv__SunDirectionalLight__pf->SetEnableLightShaftBloom(bpv__LightShaftBloom__pf);
				}
			}
		case 30:
			{
				if(IsValid(bpv__SunDirectionalLight__pf))
				{
					bpv__SunDirectionalLight__pf->SetEnableLightShaftOcclusion(bpv__LightShaftOcclusion__pf);
				}
			}
		case 31:
			{
				if(IsValid(bpv__SunDirectionalLight__pf))
				{
					bpv__SunDirectionalLight__pf->SetOcclusionMaskDarkness(bpv__OcclusionMaskDarkness__pf);
				}
			}
		case 32:
			{
				if(IsValid(bpv__SunDirectionalLight__pf))
				{
					bpv__SunDirectionalLight__pf->SetBloomScale(bpv__BloomScale__pf);
				}
			}
		case 33:
			{
				if(IsValid(bpv__SunDirectionalLight__pf))
				{
					bpv__SunDirectionalLight__pf->SetBloomThreshold(bpv__BloomThreshold__pf);
				}
			}
		case 34:
			{
				if(IsValid(bpv__SunDirectionalLight__pf))
				{
					bpv__SunDirectionalLight__pf->SetBloomTint(bpv__BloomTint__pf);
				}
			}
		case 35:
			{
				if(IsValid(bpv__SunDirectionalLight__pf))
				{
					bpv__SunDirectionalLight__pf->SetLightFunctionMaterial(bpv__LightFunctionMaterial__pf);
				}
				CurrentState = (StateStack.Num() > 0) ? StateStack.Pop(/*bAllowShrinking=*/ false) : -1;
				break;
			}
		case 36:
			{
				bpv__CallFunc_CreateDynamicMaterialInstance_ReturnValue2__pf = UKismetMaterialLibrary::CreateDynamicMaterialInstance(this, CastChecked<UMaterialInterface>(CastChecked<UDynamicClass>(ABP_LightStudio_C__pf1934637403::StaticClass())->UsedAssets[3], ECastCheckedType::NullAllowed));
			}
		case 37:
			{
				bpv__PrevisArrowMaterial__pf = bpv__CallFunc_CreateDynamicMaterialInstance_ReturnValue2__pf;
			}
		case 38:
			{
				if(IsValid(bpv__PrevisArrow__pf))
				{
					bpv__PrevisArrow__pf->SetMaterial(0, bpv__PrevisArrowMaterial__pf);
				}
			}
		case 39:
			{
				if(IsValid(bpv__PrevisArrowMaterial__pf))
				{
					bpv__PrevisArrowMaterial__pf->SetVectorParameterValue(FName(TEXT("SunColor")), bpv__LightColor__pf);
				}
				CurrentState = (StateStack.Num() > 0) ? StateStack.Pop(/*bAllowShrinking=*/ false) : -1;
				break;
			}
		case 40:
			{
				if(IsValid(bpv__ExponentialHeightFog1__pf))
				{
					bpv__ExponentialHeightFog1__pf->SetVisibility(bpv__UseFog__pf, false);
				}
			}
		case 41:
			{
				bpf__NormalizedSunAngle__pf(/*out*/ bpv__CallFunc_NormalizedSunAngle_Angle__pf);
				if(IsValid(bpv__FogBrightnessCurve__pf))
				{
					bpv__CallFunc_GetFloatValue_ReturnValue__pf = bpv__FogBrightnessCurve__pf->GetFloatValue(bpv__CallFunc_NormalizedSunAngle_Angle__pf);
				}
				bpv__CallFunc_Multiply_FloatFloat_ReturnValue2__pf = UKismetMathLibrary::Multiply_FloatFloat(bpv__FogBrightness__pf, bpv__CallFunc_GetFloatValue_ReturnValue__pf);
				bpv__CallFunc_Multiply_FloatFloat_ReturnValue3__pf = UKismetMathLibrary::Multiply_FloatFloat(bpv__GlobalBrightness__pf, bpv__CallFunc_Multiply_FloatFloat_ReturnValue2__pf);
				bpv__CallFunc_Conv_FloatToLinearColor_ReturnValue__pf = UKismetMathLibrary::Conv_FloatToLinearColor(bpv__CallFunc_Multiply_FloatFloat_ReturnValue3__pf);
				bpv__CallFunc_LinearColorLerp_ReturnValue__pf = UKismetMathLibrary::LinearColorLerp(bpv__LightColor__pf, FLinearColor(1.000000,1.000000,1.000000,1.000000), 0.500000);
				bpv__CallFunc_Multiply_LinearColorLinearColor_ReturnValue__pf = UKismetMathLibrary::Multiply_LinearColorLinearColor(bpv__FogTint__pf, bpv__CallFunc_Conv_FloatToLinearColor_ReturnValue__pf);
				bpv__CallFunc_Multiply_LinearColorLinearColor_ReturnValue2__pf = UKismetMathLibrary::Multiply_LinearColorLinearColor(bpv__CallFunc_LinearColorLerp_ReturnValue__pf, bpv__CallFunc_Multiply_LinearColorLinearColor_ReturnValue__pf);
				if(IsValid(bpv__ExponentialHeightFog1__pf))
				{
					bpv__ExponentialHeightFog1__pf->SetFogInscatteringColor(bpv__CallFunc_Multiply_LinearColorLinearColor_ReturnValue2__pf);
				}
			}
		case 42:
			{
				if(IsValid(bpv__ExponentialHeightFog1__pf))
				{
					bpv__ExponentialHeightFog1__pf->SetFogMaxOpacity(bpv__FogMaxOpacity__pf);
				}
			}
		case 43:
			{
				if(IsValid(bpv__ExponentialHeightFog1__pf))
				{
					bpv__ExponentialHeightFog1__pf->SetFogHeightFalloff(bpv__FogHeightFalloff__pf);
				}
			}
		case 44:
			{
				if(IsValid(bpv__ExponentialHeightFog1__pf))
				{
					bpv__ExponentialHeightFog1__pf->SetFogDensity(bpv__FogDensity__pf);
				}
			}
		case 45:
			{
				if(IsValid(bpv__ExponentialHeightFog1__pf))
				{
					bpv__ExponentialHeightFog1__pf->SetStartDistance(bpv__FogStartDistance__pf);
				}
			}
		case 46:
			{
				bpv__CallFunc_MakeVector_ReturnValue__pf = UKismetMathLibrary::MakeVector(0.000000, 0.000000, bpv__FogAltitude__pf);
				if(IsValid(bpv__ExponentialHeightFog1__pf))
				{
					bpv__ExponentialHeightFog1__pf->K2_SetWorldLocation(bpv__CallFunc_MakeVector_ReturnValue__pf, false, /*out*/ bpv__CallFunc_K2_SetWorldLocation_SweepHitResult2__pf, false);
				}
				CurrentState = (StateStack.Num() > 0) ? StateStack.Pop(/*bAllowShrinking=*/ false) : -1;
				break;
			}
		case 47:
			{
				if(IsValid(bpv__SkyLight1__pf))
				{
					bpv__SkyLight1__pf->RecaptureSky();
				}
			}
		case 48:
			{
				if (!bpv__UseSkylight__pf)
				{
					CurrentState = 49;
					break;
				}
				CurrentState = (StateStack.Num() > 0) ? StateStack.Pop(/*bAllowShrinking=*/ false) : -1;
				break;
			}
		case 49:
			{
				if(IsValid(bpv__SkyLight1__pf))
				{
					bpv__SkyLight1__pf->K2_DestroyComponent(this);
				}
				CurrentState = (StateStack.Num() > 0) ? StateStack.Pop(/*bAllowShrinking=*/ false) : -1;
				break;
			}
		default:
			check(false); // Invalid state
			break;
		}
	} while( CurrentState != -1 );
}
void ABP_LightStudio_C__pf1934637403::bpf__CalculateSunColor__pf()
{
	float bpv__CallFunc_NormalizedSunAngle_Angle__pf{};
	FLinearColor bpv__CallFunc_GetLinearColorValue_ReturnValue__pf(EForceInit::ForceInit);
	float bpv__CallFunc_BreakColor_R__pf{};
	float bpv__CallFunc_BreakColor_G__pf{};
	float bpv__CallFunc_BreakColor_B__pf{};
	float bpv__CallFunc_BreakColor_A__pf{};
	FLinearColor bpv__CallFunc_MakeColor_ReturnValue__pf(EForceInit::ForceInit);
	FLinearColor bpv__CallFunc_Multiply_LinearColorLinearColor_ReturnValue__pf(EForceInit::ForceInit);
	FLinearColor bpv__CallFunc_SelectColor_ReturnValue__pf(EForceInit::ForceInit);
	bpf__NormalizedSunAngle__pf(/*out*/ bpv__CallFunc_NormalizedSunAngle_Angle__pf);
	if(IsValid(bpv__SunColorCurve__pf))
	{
		bpv__CallFunc_GetLinearColorValue_ReturnValue__pf = bpv__SunColorCurve__pf->GetLinearColorValue(bpv__CallFunc_NormalizedSunAngle_Angle__pf);
	}
	UKismetMathLibrary::BreakColor(bpv__CallFunc_GetLinearColorValue_ReturnValue__pf, /*out*/ bpv__CallFunc_BreakColor_R__pf, /*out*/ bpv__CallFunc_BreakColor_G__pf, /*out*/ bpv__CallFunc_BreakColor_B__pf, /*out*/ bpv__CallFunc_BreakColor_A__pf);
	bpv__CallFunc_MakeColor_ReturnValue__pf = UKismetMathLibrary::MakeColor(bpv__CallFunc_BreakColor_R__pf, bpv__CallFunc_BreakColor_G__pf, bpv__CallFunc_BreakColor_B__pf, 1.000000);
	bpv__CallFunc_Multiply_LinearColorLinearColor_ReturnValue__pf = UKismetMathLibrary::Multiply_LinearColorLinearColor(bpv__CallFunc_MakeColor_ReturnValue__pf, bpv__SunTint__pf);
	bpv__CallFunc_SelectColor_ReturnValue__pf = UKismetMathLibrary::SelectColor(bpv__SunTint__pf, bpv__CallFunc_Multiply_LinearColorLinearColor_ReturnValue__pf, bpv__OverrideSunColor__pf);
	bpv__LightColor__pf = bpv__CallFunc_SelectColor_ReturnValue__pf;
}
void ABP_LightStudio_C__pf1934637403::bpf__SunMobility__pf()
{
	FTransform bpv_____struct_Variable__pf{};
	FTransform bpv_____struct_Variable2__pf{};
	UDirectionalLightComponent* bpv__CallFunc_AddComponent_ReturnValue__pf{};
	UDirectionalLightComponent* bpv__CallFunc_AddComponent_ReturnValue2__pf{};
	int32 CurrentState = 1;
	do
	{
		switch( CurrentState )
		{
		case 1:
			{
				if (!bpv__StationaryLightForSun__pf)
				{
					CurrentState = 4;
					break;
				}
			}
		case 2:
			{
				bpv_____struct_Variable__pf = FTransform( FQuat(0.000000,-0.000000,0.000000,1.000000), FVector(0.000000,0.000000,0.000000), FVector(1.000000,1.000000,1.000000) );
				bpv__CallFunc_AddComponent_ReturnValue__pf = CastChecked<UDirectionalLightComponent>(AddComponent(FName(TEXT("DirectionalLightComponent_0")), false, /*out*/ bpv_____struct_Variable__pf, this), ECastCheckedType::NullAllowed);
			}
		case 3:
			{
				bpv__SunDirectionalLight__pf = bpv__CallFunc_AddComponent_ReturnValue__pf;
				CurrentState = -1;
				break;
			}
		case 4:
			{
				bpv_____struct_Variable2__pf = FTransform( FQuat(0.000000,-0.000000,0.000000,1.000000), FVector(0.000000,0.000000,0.000000), FVector(1.000000,1.000000,1.000000) );
				bpv__CallFunc_AddComponent_ReturnValue2__pf = CastChecked<UDirectionalLightComponent>(AddComponent(FName(TEXT("DirectionalLightComponent_1")), false, /*out*/ bpv_____struct_Variable2__pf, this), ECastCheckedType::NullAllowed);
			}
		case 5:
			{
				bpv__SunDirectionalLight__pf = bpv__CallFunc_AddComponent_ReturnValue2__pf;
				CurrentState = -1;
				break;
			}
		default:
			break;
		}
	} while( CurrentState != -1 );
}
void ABP_LightStudio_C__pf1934637403::bpf__NormalizedSunAngle__pf(/*out*/ float& bpp__Angle__pf)
{
	FRotator bpv__CallFunc_K2_GetActorRotation_ReturnValue__pf(EForceInit::ForceInit);
	float bpv__CallFunc_BreakRotator_Roll__pf{};
	float bpv__CallFunc_BreakRotator_Pitch__pf{};
	float bpv__CallFunc_BreakRotator_Yaw__pf{};
	float bpv__CallFunc_Subtract_FloatFloat_ReturnValue__pf{};
	float bpv__CallFunc_Abs_ReturnValue__pf{};
	float bpv__CallFunc_Divide_FloatFloat_ReturnValue__pf{};
	float bpv__CallFunc_Abs_ReturnValue2__pf{};
	float bpv__CallFunc_Add_FloatFloat_ReturnValue__pf{};
	bpv__CallFunc_K2_GetActorRotation_ReturnValue__pf = K2_GetActorRotation();
	UKismetMathLibrary::BreakRotator(bpv__CallFunc_K2_GetActorRotation_ReturnValue__pf, /*out*/ bpv__CallFunc_BreakRotator_Roll__pf, /*out*/ bpv__CallFunc_BreakRotator_Pitch__pf, /*out*/ bpv__CallFunc_BreakRotator_Yaw__pf);
	bpv__CallFunc_Subtract_FloatFloat_ReturnValue__pf = UKismetMathLibrary::Subtract_FloatFloat(bpv__CallFunc_BreakRotator_Pitch__pf, 90.000000);
	bpv__CallFunc_Abs_ReturnValue__pf = UKismetMathLibrary::Abs(bpv__CallFunc_Subtract_FloatFloat_ReturnValue__pf);
	bpv__CallFunc_Divide_FloatFloat_ReturnValue__pf = FCustomThunkTemplates::Divide_FloatFloat(bpv__CallFunc_Abs_ReturnValue__pf, 90.000000);
	bpv__CallFunc_Abs_ReturnValue2__pf = UKismetMathLibrary::Abs(bpv__CallFunc_Divide_FloatFloat_ReturnValue__pf);
	bpv__CallFunc_Add_FloatFloat_ReturnValue__pf = UKismetMathLibrary::Add_FloatFloat(bpv__CallFunc_Abs_ReturnValue2__pf, -1.000000);
	bpp__Angle__pf = bpv__CallFunc_Add_FloatFloat_ReturnValue__pf;
}
void ABP_LightStudio_C__pf1934637403::bpf__AtmosphereDensity__pf()
{
	FTransform bpv_____struct_Variable__pf{};
	FTransform bpv_____struct_Variable2__pf{};
	UAtmosphericFogComponent* bpv__CallFunc_AddComponent_ReturnValue__pf{};
	UAtmosphericFogComponent* bpv__CallFunc_AddComponent_ReturnValue2__pf{};
	int32 CurrentState = 1;
	do
	{
		switch( CurrentState )
		{
		case 1:
			{
				if (!bpv__HighDensityAtmosphere__pf)
				{
					CurrentState = 5;
					break;
				}
			}
		case 2:
			{
				bpv_____struct_Variable2__pf = FTransform( FQuat(0.000000,-0.000000,0.000000,1.000000), FVector(0.000000,0.000000,0.000000), FVector(1.000000,1.000000,1.000000) );
				bpv__CallFunc_AddComponent_ReturnValue2__pf = CastChecked<UAtmosphericFogComponent>(AddComponent(FName(TEXT("AtmosphericFogComponent_1")), false, /*out*/ bpv_____struct_Variable2__pf, this), ECastCheckedType::NullAllowed);
			}
		case 3:
			{
				bpv__AtmosphericFog__pf = bpv__CallFunc_AddComponent_ReturnValue2__pf;
			}
		case 4:
			{
				if(IsValid(bpv__AtmosphericFog__pf))
				{
					bpv__AtmosphericFog__pf->SetPrecomputeParams(bpv__AtmosphereDensityHeight__pf, bpv__AtmosphereMaxScatteringOrder__pf, bpv__AtmosphereAltitudeSampleNumber__pf);
				}
				CurrentState = -1;
				break;
			}
		case 5:
			{
				bpv_____struct_Variable__pf = FTransform( FQuat(0.000000,-0.000000,0.000000,1.000000), FVector(0.000000,0.000000,0.000000), FVector(1.000000,1.000000,1.000000) );
				bpv__CallFunc_AddComponent_ReturnValue__pf = CastChecked<UAtmosphericFogComponent>(AddComponent(FName(TEXT("AtmosphericFogComponent_0")), false, /*out*/ bpv_____struct_Variable__pf, this), ECastCheckedType::NullAllowed);
			}
		case 6:
			{
				bpv__AtmosphericFog__pf = bpv__CallFunc_AddComponent_ReturnValue__pf;
				CurrentState = -1;
				break;
			}
		default:
			break;
		}
	} while( CurrentState != -1 );
}
void ABP_LightStudio_C__pf1934637403::__StaticDependencies_CommonAssets(TArray<FBlueprintDependencyData>& AssetsToLoad)
{
	FBlueprintDependencyData LocAssets[] =
	{
		FBlueprintDependencyData(TEXT("/Game/StarterContent/Blueprints/Assets/Skybox"), TEXT("Skybox"), TEXT("/Script/Engine"), TEXT("StaticMesh")),
		FBlueprintDependencyData(TEXT("/Game/StarterContent/Blueprints/Assets/M_LightStage_Skybox_Master"), TEXT("M_LightStage_Skybox_Master"), TEXT("/Script/Engine"), TEXT("Material")),
		FBlueprintDependencyData(TEXT("/Game/StarterContent/Blueprints/Assets/SM_Arrows"), TEXT("SM_Arrows"), TEXT("/Script/Engine"), TEXT("StaticMesh")),
		FBlueprintDependencyData(TEXT("/Game/StarterContent/Blueprints/Assets/M_LightStage_Arrows"), TEXT("M_LightStage_Arrows"), TEXT("/Script/Engine"), TEXT("Material")),
		FBlueprintDependencyData(TEXT("/Game/StarterContent/Blueprints/Assets/SunlightColorLUT"), TEXT("SunlightColorLUT"), TEXT("/Script/Engine"), TEXT("CurveLinearColor")),
		FBlueprintDependencyData(TEXT("/Game/StarterContent/Blueprints/Assets/FogBrightnessLUT"), TEXT("FogBrightnessLUT"), TEXT("/Script/Engine"), TEXT("CurveFloat")),
		FBlueprintDependencyData(TEXT("/Game/StarterContent/HDRI/HDRI_Epic_Courtyard_Daylight"), TEXT("HDRI_Epic_Courtyard_Daylight"), TEXT("/Script/Engine"), TEXT("TextureCube")),
		FBlueprintDependencyData(TEXT("/Game/StarterContent/Blueprints/Assets/M_LightStage_Skybox_Black"), TEXT("M_LightStage_Skybox_Black"), TEXT("/Script/Engine"), TEXT("MaterialInstanceConstant")),
		FBlueprintDependencyData(TEXT("/Game/StarterContent/Blueprints/Assets/M_LightStage_Skybox_HDRI"), TEXT("M_LightStage_Skybox_HDRI"), TEXT("/Script/Engine"), TEXT("MaterialInstanceConstant")),
	};
	for(auto& LocAsset : LocAssets) { AssetsToLoad.Add(LocAsset); } 
}
void ABP_LightStudio_C__pf1934637403::__StaticDependencies_DirectlyUsedAssets(TArray<FBlueprintDependencyData>& AssetsToLoad)
{
	__StaticDependencies_CommonAssets(AssetsToLoad);
}
void ABP_LightStudio_C__pf1934637403::__StaticDependenciesAssets(TArray<FBlueprintDependencyData>& AssetsToLoad)
{
	__StaticDependencies_CommonAssets(AssetsToLoad);
}
struct FRegisterHelper__ABP_LightStudio_C__pf1934637403
{
	FRegisterHelper__ABP_LightStudio_C__pf1934637403()
	{
		FConvertedBlueprintsDependencies::Get().RegisterClass(TEXT("/Game/StarterContent/Blueprints/BP_LightStudio"), &ABP_LightStudio_C__pf1934637403::__StaticDependenciesAssets);
	}
	static FRegisterHelper__ABP_LightStudio_C__pf1934637403 Instance;
};
FRegisterHelper__ABP_LightStudio_C__pf1934637403 FRegisterHelper__ABP_LightStudio_C__pf1934637403::Instance;
#ifdef _MSC_VER
#pragma warning (pop)
#endif
