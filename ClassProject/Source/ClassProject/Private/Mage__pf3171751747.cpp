#include "ClassProject.h"
#include "Mage__pf3171751747.h"
#include "GeneratedCodeHelpers.h"
#include "Runtime/Engine/Classes/Engine/InputKeyDelegateBinding.h"
#include "Runtime/Engine/Classes/Engine/SimpleConstructionScript.h"
#include "Runtime/Engine/Classes/Engine/SCS_Node.h"
#include "Runtime/Engine/Classes/Components/SceneComponent.h"
#include "Mage__pf3171751747.h"
#include "Fireball__pf1471916900.h"
#include "Runtime/Engine/Classes/GameFramework/Actor.h"
#include "Runtime/Engine/Classes/Components/ActorComponent.h"
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
#include "Runtime/Engine/Classes/Materials/Material.h"
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
#include "Runtime/Engine/Classes/Components/BillboardComponent.h"
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
#include "Runtime/Engine/Classes/Components/StaticMeshComponent.h"
#include "Runtime/Engine/Classes/Engine/StaticMesh.h"
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
#include "Runtime/Engine/Classes/Components/CapsuleComponent.h"
#include "Runtime/Engine/Classes/GameFramework/CharacterMovementComponent.h"
#include "Runtime/Engine/Classes/AI/Navigation/NavAgentInterface.h"
#include "Runtime/Engine/Classes/AI/Navigation/NavRelevantInterface.h"
#include "Runtime/Engine/Classes/Components/ChildActorComponent.h"
#include "inGameHUD__pf3171751747.h"
#include "Runtime/Engine/Classes/Kismet/KismetSystemLibrary.h"
#include "Runtime/Engine/Classes/Kismet/KismetMathLibrary.h"
#include "Runtime/Engine/Classes/Kismet/GameplayStatics.h"
#include "Runtime/Engine/Classes/Sound/ReverbEffect.h"
#include "Runtime/Engine/Classes/Engine/Blueprint.h"
#include "Runtime/Engine/Classes/Engine/BlueprintCore.h"
#include "Runtime/Engine/Classes/GameFramework/SaveGame.h"
#include "Runtime/Engine/Classes/Components/AudioComponent.h"
#include "Runtime/Engine/Classes/Sound/SoundWave.h"
#include "Runtime/Engine/Classes/Sound/SoundGroups.h"
#include "Runtime/Engine/Classes/Engine/GameInstance.h"
#include "Runtime/Engine/Classes/GameFramework/OnlineSession.h"
#include "Runtime/Engine/Classes/Engine/LocalPlayer.h"
#include "Runtime/Engine/Classes/Engine/GameViewportClient.h"
#include "Runtime/Engine/Classes/Engine/ScriptViewportClient.h"
#include "Runtime/Engine/Classes/Engine/DebugDisplayProperty.h"
#include "Runtime/Engine/Classes/Engine/Console.h"
#include "Runtime/Engine/Classes/Engine/Engine.h"
#include "Runtime/Engine/Classes/Engine/LevelScriptActor.h"
#include "Runtime/Engine/Classes/GameFramework/GameUserSettings.h"
#include "Runtime/Engine/Classes/PhysicsEngine/PhysicsCollisionHandler.h"
#include "Runtime/Engine/Classes/AI/Navigation/AvoidanceManager.h"
#include "Runtime/Engine/Classes/AI/Navigation/NavigationSystem.h"
#include "Runtime/Engine/Classes/Kismet/BlueprintFunctionLibrary.h"
#include "Runtime/Engine/Classes/AI/Navigation/NavigationPath.h"
#include "Runtime/Engine/Classes/AI/Navigation/NavMeshBoundsVolume.h"
#include "Runtime/Engine/Classes/GameFramework/WorldSettings.h"
#include "Runtime/Engine/Classes/Sound/AudioVolume.h"
#include "Runtime/Engine/Classes/GameFramework/GameNetworkManager.h"
#include "Runtime/Engine/Classes/GameFramework/GameMode.h"
#include "Runtime/Engine/Classes/GameFramework/GameState.h"
#include "Runtime/Engine/Classes/GameFramework/GameSession.h"
#include "Runtime/Engine/Classes/GameFramework/DefaultPhysicsVolume.h"
#include "DmgTypeBP_Environmental__pf2398200284.h"
#include "Runtime/UMG/Public/Blueprint/WidgetBlueprintLibrary.h"
#include "Runtime/UMG/Public/Components/SlateWrapperTypes.h"
#include "Runtime/UMG/Public/Components/Widget.h"
#include "Runtime/UMG/Public/Components/Visual.h"
#include "Runtime/UMG/Public/Blueprint/WidgetNavigation.h"
#include "Runtime/SlateCore/Public/Input/NavigationReply.h"
#include "Runtime/UMG/Public/Slate/WidgetTransform.h"
#include "Runtime/SlateCore/Public/Styling/SlateTypes.h"
#include "Runtime/UMG/Public/Components/PanelWidget.h"
#include "Runtime/UMG/Public/Components/PanelSlot.h"
#include "Runtime/SlateCore/Public/Styling/SlateBrush.h"
#include "Runtime/SlateCore/Public/Styling/SlateColor.h"
#include "Runtime/SlateCore/Public/Layout/Margin.h"
#include "Runtime/SlateCore/Public/Input/Events.h"
#include "Runtime/SlateCore/Public/Layout/Geometry.h"
#include "Runtime/UMG/Public/Blueprint/UserWidget.h"
#include "Runtime/UMG/Public/Animation/UMGSequencePlayer.h"
#include "Runtime/UMG/Public/Animation/WidgetAnimation.h"
#include "Runtime/MovieScene/Public/MovieSceneSequence.h"
#include "Runtime/UMG/Public/Animation/WidgetAnimationBinding.h"
#include "Runtime/MovieScene/Public/MovieScene.h"
#include "Runtime/MovieScene/Public/MovieSceneTrack.h"
#include "Runtime/MovieScene/Public/MovieSceneBinding.h"
#include "Runtime/MovieScene/Public/MovieScenePossessable.h"
#include "Runtime/MovieScene/Public/MovieSceneSpawnable.h"
#include "Runtime/UMG/Public/Blueprint/WidgetTree.h"
#include "Runtime/UMG/Public/Blueprint/DragDropOperation.h"
#include "Runtime/Slate/Public/Widgets/Layout/Anchors.h"
#include "Runtime/UMG/Public/Components/NamedSlotInterface.h"
#include "Runtime/Engine/Classes/Engine/BlueprintGeneratedClass.h"
#include "Runtime/Engine/Classes/GameFramework/SpringArmComponent.h"
#include "ThirdPerson_AnimBP__pf4153901168.h"
#include "Runtime/Engine/Classes/Components/ArrowComponent.h"
#include "FireballExplosion__pf3346625017.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
AMage_C__pf3171751747::AMage_C__pf3171751747(const FObjectInitializer& ObjectInitializer) : Super()
{
	if(HasAnyFlags(RF_ClassDefaultObject) && (AMage_C__pf3171751747::StaticClass() == GetClass()))
	{
		AMage_C__pf3171751747::__CustomDynamicClassInitialization(CastChecked<UDynamicClass>(GetClass()));
	}
	
	auto __Local__0 = CastChecked<UCapsuleComponent>(GetDefaultSubobjectByName(TEXT("CollisionCylinder")));
	auto __Local__1 = CastChecked<UCharacterMovementComponent>(GetDefaultSubobjectByName(TEXT("CharMoveComp")));
	static TWeakObjectPtr<UProperty> __Local__3{};
	const UProperty* __Local__2 = __Local__3.Get();
	if (nullptr == __Local__2)
	{
		__Local__2 = (UNavMovementComponent::StaticClass())->FindPropertyByName(FName(TEXT("bUseAccelerationForPaths")));
		check(__Local__2);
		__Local__3 = __Local__2;
	}
	(((UBoolProperty*)__Local__2)->SetPropertyValue_InContainer((__Local__1), false, 0));
	auto __Local__4 = CastChecked<USkeletalMeshComponent>(GetDefaultSubobjectByName(TEXT("CharacterMesh0")));
	__Local__4->AnimClass = UThirdPerson_AnimBP_C__pf4153901168::StaticClass();
	__Local__4->SkeletalMesh = CastChecked<USkeletalMesh>(CastChecked<UDynamicClass>(AMage_C__pf3171751747::StaticClass())->UsedAssets[10], ECastCheckedType::NullAllowed);
	__Local__4->RelativeLocation = FVector(0.000000, 0.000000, -97.000000);
	__Local__4->RelativeRotation = FRotator(0.000000, 270.000000, 0.000000);
	auto __Local__5 = CastChecked<USpringArmComponent>(GetDefaultSubobjectByName(TEXT("CameraBoom")));
	auto __Local__6 = CastChecked<UCameraComponent>(GetDefaultSubobjectByName(TEXT("FollowCamera")));
	bpv__Health__pf = 100.000000f;
	bpv__Stamina__pf = 100.000000f;
}
void AMage_C__pf3171751747::PostLoadSubobjects(FObjectInstancingGraph* OuterInstanceGraph)
{
	Super::PostLoadSubobjects(OuterInstanceGraph);
}
void AMage_C__pf3171751747::__CustomDynamicClassInitialization(UDynamicClass* InDynamicClass)
{
	ensure(0 == InDynamicClass->ReferencedConvertedFields.Num());
	ensure(0 == InDynamicClass->MiscConvertedSubobjects.Num());
	ensure(0 == InDynamicClass->DynamicBindingObjects.Num());
	ensure(0 == InDynamicClass->ComponentTemplates.Num());
	ensure(0 == InDynamicClass->Timelines.Num());
	ensure(nullptr == InDynamicClass->AnimClassImplementation);
	InDynamicClass->AssembleReferenceTokenStream();
	// List of all referenced converted classes
	extern UClass* Z_Construct_UClass_AFireball_C__pf1471916900();
	InDynamicClass->ReferencedConvertedFields.Add(Z_Construct_UClass_AFireball_C__pf1471916900());
	extern UClass* Z_Construct_UClass_AFireballExplosion_C__pf3346625017();
	InDynamicClass->ReferencedConvertedFields.Add(Z_Construct_UClass_AFireballExplosion_C__pf3346625017());
	extern UClass* Z_Construct_UClass_UinGameHUD_C__pf3171751747();
	InDynamicClass->ReferencedConvertedFields.Add(Z_Construct_UClass_UinGameHUD_C__pf3171751747());
	extern UClass* Z_Construct_UClass_UThirdPerson_AnimBP_C__pf4153901168();
	InDynamicClass->ReferencedConvertedFields.Add(Z_Construct_UClass_UThirdPerson_AnimBP_C__pf4153901168());
	FConvertedBlueprintsDependencies::FillUsedAssetsInDynamicClass(InDynamicClass, &__StaticDependencies_DirectlyUsedAssets);
	auto __Local__7 = NewObject<UInputKeyDelegateBinding>(InDynamicClass, UInputKeyDelegateBinding::StaticClass(), TEXT("InputKeyDelegateBinding_3"));
	InDynamicClass->DynamicBindingObjects.Add(__Local__7);
	__Local__7->InputKeyDelegateBindings = TArray<FBlueprintInputKeyDelegateBinding> ();
	__Local__7->InputKeyDelegateBindings.AddUninitialized(4);
	FBlueprintInputKeyDelegateBinding::StaticStruct()->InitializeStruct(__Local__7->InputKeyDelegateBindings.GetData(), 4);
	auto& __Local__8 = __Local__7->InputKeyDelegateBindings[0];
	__Local__8.InputChord.Key = FKey(TEXT("LeftMouseButton"));
	__Local__8.InputKeyEvent = EInputEvent::IE_Released;
	__Local__8.FunctionNameToBind = FName(TEXT("InpActEvt_LeftMouseButton_K2Node_InputKeyEvent_15"));
	auto& __Local__9 = __Local__7->InputKeyDelegateBindings[1];
	__Local__9.InputChord.Key = FKey(TEXT("F"));
	__Local__9.InputKeyEvent = EInputEvent::IE_Released;
	__Local__9.FunctionNameToBind = FName(TEXT("InpActEvt_F_K2Node_InputKeyEvent_14"));
	auto& __Local__10 = __Local__7->InputKeyDelegateBindings[2];
	__Local__10.InputChord.Key = FKey(TEXT("G"));
	__Local__10.InputKeyEvent = EInputEvent::IE_Released;
	__Local__10.FunctionNameToBind = FName(TEXT("InpActEvt_G_K2Node_InputKeyEvent_13"));
	auto& __Local__11 = __Local__7->InputKeyDelegateBindings[3];
	__Local__11.InputChord.Key = FKey(TEXT("T"));
	__Local__11.InputKeyEvent = EInputEvent::IE_Released;
	__Local__11.FunctionNameToBind = FName(TEXT("InpActEvt_T_K2Node_InputKeyEvent_12"));
}
void AMage_C__pf3171751747::bpf__ExecuteUbergraph_Mage__pf_0(int32 bpp__EntryPoint__pf)
{
	check(bpp__EntryPoint__pf == 1);
	UKismetSystemLibrary::K2_ClearAndInvalidateTimerHandle(this, /*out*/ b0l__CallFunc_K2_SetTimer_ReturnValue__pf);
	return; //KCST_EndOfThread
}
void AMage_C__pf3171751747::bpf__ExecuteUbergraph_Mage__pf_1(int32 bpp__EntryPoint__pf)
{
	TArray< int32, TInlineAllocator<8> > StateStack;

	int32 CurrentState = bpp__EntryPoint__pf;
	do
	{
		switch( CurrentState )
		{
		case 3:
			{
				b0l__CallFunc_LessEqual_FloatFloat_ReturnValue__pf = UKismetMathLibrary::LessEqual_FloatFloat(bpv__Stamina__pf, 0.000000);
				if (!b0l__CallFunc_LessEqual_FloatFloat_ReturnValue__pf)
				{
					CurrentState = (StateStack.Num() > 0) ? StateStack.Pop(/*bAllowShrinking=*/ false) : -1;
					break;
				}
			}
		case 4:
			{
				bpv__Stamina__pf = 0.000000;
				CurrentState = (StateStack.Num() > 0) ? StateStack.Pop(/*bAllowShrinking=*/ false) : -1;
				break;
			}
		case 20:
			{
				StateStack.Push(21);
				CurrentState = 3;
				break;
			}
		case 21:
			{
			}
		case 22:
			{
				b0l__CallFunc_Less_FloatFloat_ReturnValue__pf = UKismetMathLibrary::Less_FloatFloat(bpv__Health__pf, 0.100000);
				if (!b0l__CallFunc_Less_FloatFloat_ReturnValue__pf)
				{
					CurrentState = (StateStack.Num() > 0) ? StateStack.Pop(/*bAllowShrinking=*/ false) : -1;
					break;
				}
			}
		case 23:
			{
				K2_DestroyActor();
				CurrentState = (StateStack.Num() > 0) ? StateStack.Pop(/*bAllowShrinking=*/ false) : -1;
				break;
			}
		case 25:
			{
				CurrentState = 20;
				break;
			}
		default:
			check(false); // Invalid state
			break;
		}
	} while( CurrentState != -1 );
}
void AMage_C__pf3171751747::bpf__ExecuteUbergraph_Mage__pf_2(int32 bpp__EntryPoint__pf)
{
	check(bpp__EntryPoint__pf == 5);
	b0l__CallFunc_K2_SetTimer_ReturnValue__pf = UKismetSystemLibrary::K2_SetTimer(this, FString(TEXT("TakeForceFieldDamage")), 0.100000, true);
	return; //KCST_EndOfThread
}
void AMage_C__pf3171751747::bpf__ExecuteUbergraph_Mage__pf_3(int32 bpp__EntryPoint__pf)
{
	check(bpp__EntryPoint__pf == 8);
	// optimized KCST_UnconditionalGoto
	bpf__TestStamina__pf();
	return; //KCST_EndOfThread
}
void AMage_C__pf3171751747::bpf__ExecuteUbergraph_Mage__pf_4(int32 bpp__EntryPoint__pf)
{
	TArray< int32, TInlineAllocator<8> > StateStack;

	int32 CurrentState = bpp__EntryPoint__pf;
	do
	{
		switch( CurrentState )
		{
		case 9:
			{
				StateStack.Push(10);
				CurrentState = 12;
				break;
			}
		case 10:
			{
			}
		case 11:
			{
				b0l__CallFunc_K2_SetTimer_ReturnValue2__pf = UKismetSystemLibrary::K2_SetTimer(this, FString(TEXT("StaminaRegeneration")), 0.100000, true);
				CurrentState = (StateStack.Num() > 0) ? StateStack.Pop(/*bAllowShrinking=*/ false) : -1;
				break;
			}
		case 12:
			{
				bpv__Stamina__pf = 100.000000;
			}
		case 13:
			{
				bpv__Health__pf = 100.000000;
			}
		case 14:
			{
				b0l__CallFunc_GetPlayerController_ReturnValue__pf = UGameplayStatics::GetPlayerController(this, 0);
				b0l__CallFunc_Create_ReturnValue__pf = CastChecked<UinGameHUD_C__pf3171751747>(UWidgetBlueprintLibrary::Create(this, UinGameHUD_C__pf3171751747::StaticClass(), b0l__CallFunc_GetPlayerController_ReturnValue__pf), ECastCheckedType::NullAllowed);
			}
		case 15:
			{
				if(IsValid(b0l__CallFunc_Create_ReturnValue__pf))
				{
					b0l__CallFunc_Create_ReturnValue__pf->AddToViewport(0);
				}
				CurrentState = (StateStack.Num() > 0) ? StateStack.Pop(/*bAllowShrinking=*/ false) : -1;
				break;
			}
		case 29:
			{
				CurrentState = 9;
				break;
			}
		default:
			check(false); // Invalid state
			break;
		}
	} while( CurrentState != -1 );
}
void AMage_C__pf3171751747::bpf__ExecuteUbergraph_Mage__pf_5(int32 bpp__EntryPoint__pf)
{
	check(bpp__EntryPoint__pf == 30);
	// optimized KCST_UnconditionalGoto
	bpf__StaminaRegeneration__pf();
	return; //KCST_EndOfThread
}
void AMage_C__pf3171751747::bpf__ExecuteUbergraph_Mage__pf_6(int32 bpp__EntryPoint__pf)
{
	check(bpp__EntryPoint__pf == 17);
	b0l__CallFunc_K2_GetActorLocation_ReturnValue__pf = K2_GetActorLocation();
	b0l__CallFunc_GetControlRotation_ReturnValue__pf = GetControlRotation();
	b0l__CallFunc_GetForwardVector_ReturnValue__pf = UKismetMathLibrary::GetForwardVector(b0l__CallFunc_GetControlRotation_ReturnValue__pf);
	b0l__CallFunc_Multiply_VectorFloat_ReturnValue__pf = UKismetMathLibrary::Multiply_VectorFloat(b0l__CallFunc_GetForwardVector_ReturnValue__pf, 160.000000);
	b0l__CallFunc_Add_VectorVector_ReturnValue__pf = UKismetMathLibrary::Add_VectorVector(b0l__CallFunc_K2_GetActorLocation_ReturnValue__pf, b0l__CallFunc_Multiply_VectorFloat_ReturnValue__pf);
	b0l__CallFunc_MakeTransform_ReturnValue__pf = UKismetMathLibrary::MakeTransform(b0l__CallFunc_Add_VectorVector_ReturnValue__pf, b0l__CallFunc_GetControlRotation_ReturnValue__pf, FVector(1.000000,1.000000,1.000000));
	b0l__CallFunc_BeginDeferredActorSpawnFromClass_ReturnValue__pf = UGameplayStatics::BeginDeferredActorSpawnFromClass(this, AFireball_C__pf1471916900::StaticClass(), /*out*/ b0l__CallFunc_MakeTransform_ReturnValue__pf, ESpawnActorCollisionHandlingMethod::Undefined, nullptr);
	b0l__CallFunc_K2_GetActorLocation_ReturnValue__pf = K2_GetActorLocation();
	b0l__CallFunc_GetControlRotation_ReturnValue__pf = GetControlRotation();
	b0l__CallFunc_GetForwardVector_ReturnValue__pf = UKismetMathLibrary::GetForwardVector(b0l__CallFunc_GetControlRotation_ReturnValue__pf);
	b0l__CallFunc_Multiply_VectorFloat_ReturnValue__pf = UKismetMathLibrary::Multiply_VectorFloat(b0l__CallFunc_GetForwardVector_ReturnValue__pf, 160.000000);
	b0l__CallFunc_Add_VectorVector_ReturnValue__pf = UKismetMathLibrary::Add_VectorVector(b0l__CallFunc_K2_GetActorLocation_ReturnValue__pf, b0l__CallFunc_Multiply_VectorFloat_ReturnValue__pf);
	b0l__CallFunc_MakeTransform_ReturnValue__pf = UKismetMathLibrary::MakeTransform(b0l__CallFunc_Add_VectorVector_ReturnValue__pf, b0l__CallFunc_GetControlRotation_ReturnValue__pf, FVector(1.000000,1.000000,1.000000));
	b0l__CallFunc_FinishSpawningActor_ReturnValue__pf = CastChecked<AFireball_C__pf1471916900>(UGameplayStatics::FinishSpawningActor(b0l__CallFunc_BeginDeferredActorSpawnFromClass_ReturnValue__pf, /*out*/ b0l__CallFunc_MakeTransform_ReturnValue__pf), ECastCheckedType::NullAllowed);
	return; //KCST_EndOfThread
}
void AMage_C__pf3171751747::bpf__ExecuteUbergraph_Mage__pf_7(int32 bpp__EntryPoint__pf)
{
	check(bpp__EntryPoint__pf == 28);
	// optimized KCST_UnconditionalGoto
	bpf__TestStamina__pf();
	return; //KCST_EndOfThread
}
void AMage_C__pf3171751747::bpf__ExecuteUbergraph_Mage__pf_8(int32 bpp__EntryPoint__pf)
{
	check(bpp__EntryPoint__pf == 27);
	// optimized KCST_UnconditionalGoto
	bpf__TestDamage__pf();
	return; //KCST_EndOfThread
}
void AMage_C__pf3171751747::bpf__PlayerOutForceField__pf()
{
	bpf__ExecuteUbergraph_Mage__pf_0(1);
}
void AMage_C__pf3171751747::bpf__PlayerInForceField__pf()
{
	bpf__ExecuteUbergraph_Mage__pf_2(5);
}
void AMage_C__pf3171751747::OnJumped_Implementation()
{
	bpf__ExecuteUbergraph_Mage__pf_3(8);
}
void AMage_C__pf3171751747::bpf__ReceiveTick__pf(float bpp__DeltaSeconds__pf)
{
	b0l__K2Node_Event_DeltaSeconds__pf = bpp__DeltaSeconds__pf;
	bpf__ExecuteUbergraph_Mage__pf_1(25);
}
void AMage_C__pf3171751747::bpf__ReceiveBeginPlay__pf()
{
	bpf__ExecuteUbergraph_Mage__pf_4(29);
}
void AMage_C__pf3171751747::bpf__InpActEvt_T_K2Node_InputKeyEvent_12__pf(FKey bpp__Key__pf)
{
	b0l__K2Node_InputKeyEvent_Key__pf = bpp__Key__pf;
	bpf__ExecuteUbergraph_Mage__pf_5(30);
}
void AMage_C__pf3171751747::bpf__InpActEvt_G_K2Node_InputKeyEvent_13__pf(FKey bpp__Key__pf)
{
	b0l__K2Node_InputKeyEvent_Key2__pf = bpp__Key__pf;
	bpf__ExecuteUbergraph_Mage__pf_7(28);
}
void AMage_C__pf3171751747::bpf__InpActEvt_F_K2Node_InputKeyEvent_14__pf(FKey bpp__Key__pf)
{
	b0l__K2Node_InputKeyEvent_Key3__pf = bpp__Key__pf;
	bpf__ExecuteUbergraph_Mage__pf_8(27);
}
void AMage_C__pf3171751747::bpf__InpActEvt_LeftMouseButton_K2Node_InputKeyEvent_15__pf(FKey bpp__Key__pf)
{
	b0l__K2Node_InputKeyEvent_Key4__pf = bpp__Key__pf;
	bpf__ExecuteUbergraph_Mage__pf_6(17);
}
void AMage_C__pf3171751747::bpf__UserConstructionScript__pf()
{
}
void AMage_C__pf3171751747::bpf__TestDamage__pf()
{
	float bpv__CallFunc_Subtract_FloatFloat_ReturnValue__pf{};
	bpv__CallFunc_Subtract_FloatFloat_ReturnValue__pf = UKismetMathLibrary::Subtract_FloatFloat(bpv__Health__pf, 5.000000);
	bpv__Health__pf = bpv__CallFunc_Subtract_FloatFloat_ReturnValue__pf;
}
void AMage_C__pf3171751747::bpf__GetHealthPercentage__pf(/*out*/ float& bpp__Perc__pf)
{
	ACharacter* bpv__CallFunc_GetPlayerCharacter_ReturnValue__pf{};
	AMage_C__pf3171751747* bpv__K2Node_DynamicCast_AsMage__pf{};
	bool bpv__K2Node_DynamicCast_bSuccess__pf{};
	float bpv__CallFunc_Divide_FloatFloat_ReturnValue__pf{};
	int32 CurrentState = 3;
	do
	{
		switch( CurrentState )
		{
		case 3:
			{
			}
		case 1:
			{
				bpv__CallFunc_GetPlayerCharacter_ReturnValue__pf = UGameplayStatics::GetPlayerCharacter(this, 0);
				bpv__K2Node_DynamicCast_AsMage__pf = Cast<AMage_C__pf3171751747>(bpv__CallFunc_GetPlayerCharacter_ReturnValue__pf);
				bpv__K2Node_DynamicCast_bSuccess__pf = (bpv__K2Node_DynamicCast_AsMage__pf != nullptr);;
				if (!bpv__K2Node_DynamicCast_bSuccess__pf)
				{
					CurrentState = 2;
					break;
				}
			}
		case 2:
			{
				float  __Local__12 = 0.000000;
				bpv__CallFunc_Divide_FloatFloat_ReturnValue__pf = FCustomThunkTemplates::Divide_FloatFloat(((IsValid(bpv__K2Node_DynamicCast_AsMage__pf)) ? (bpv__K2Node_DynamicCast_AsMage__pf->bpv__Health__pf) : (__Local__12)), 100.000000);
				bpp__Perc__pf = bpv__CallFunc_Divide_FloatFloat_ReturnValue__pf;
				CurrentState = -1;
				break;
			}
		default:
			break;
		}
	} while( CurrentState != -1 );
}
void AMage_C__pf3171751747::bpf__StaminaRegeneration__pf()
{
	ACharacter* bpv__CallFunc_GetPlayerCharacter_ReturnValue__pf{};
	AMage_C__pf3171751747* bpv__K2Node_DynamicCast_AsMage__pf{};
	bool bpv__K2Node_DynamicCast_bSuccess__pf{};
	bool bpv__CallFunc_GreaterEqual_FloatFloat_ReturnValue__pf{};
	float bpv__CallFunc_Add_FloatFloat_ReturnValue__pf{};
	int32 CurrentState = 4;
	do
	{
		switch( CurrentState )
		{
		case 4:
			{
			}
		case 1:
			{
				bpv__CallFunc_GetPlayerCharacter_ReturnValue__pf = UGameplayStatics::GetPlayerCharacter(this, 0);
				bpv__K2Node_DynamicCast_AsMage__pf = Cast<AMage_C__pf3171751747>(bpv__CallFunc_GetPlayerCharacter_ReturnValue__pf);
				bpv__K2Node_DynamicCast_bSuccess__pf = (bpv__K2Node_DynamicCast_AsMage__pf != nullptr);;
				if (!bpv__K2Node_DynamicCast_bSuccess__pf)
				{
					CurrentState = 2;
					break;
				}
			}
		case 2:
			{
				float  __Local__13 = 0.000000;
				bpv__CallFunc_GreaterEqual_FloatFloat_ReturnValue__pf = UKismetMathLibrary::GreaterEqual_FloatFloat(((IsValid(bpv__K2Node_DynamicCast_AsMage__pf)) ? (bpv__K2Node_DynamicCast_AsMage__pf->bpv__Stamina__pf) : (__Local__13)), 99.900002);
				if (!bpv__CallFunc_GreaterEqual_FloatFloat_ReturnValue__pf)
				{
					CurrentState = 3;
					break;
				}
				CurrentState = -1;
				break;
			}
		case 3:
			{
				float  __Local__14 = 0.000000;
				bpv__CallFunc_Add_FloatFloat_ReturnValue__pf = UKismetMathLibrary::Add_FloatFloat(((IsValid(bpv__K2Node_DynamicCast_AsMage__pf)) ? (bpv__K2Node_DynamicCast_AsMage__pf->bpv__Stamina__pf) : (__Local__14)), 1.000000);
				if(IsValid(bpv__K2Node_DynamicCast_AsMage__pf))
				{
					bpv__K2Node_DynamicCast_AsMage__pf->bpv__Stamina__pf = bpv__CallFunc_Add_FloatFloat_ReturnValue__pf;
				}
				CurrentState = -1;
				break;
			}
		default:
			break;
		}
	} while( CurrentState != -1 );
}
void AMage_C__pf3171751747::bpf__TestStamina__pf()
{
	float bpv__CallFunc_Subtract_FloatFloat_ReturnValue__pf{};
	bpv__CallFunc_Subtract_FloatFloat_ReturnValue__pf = UKismetMathLibrary::Subtract_FloatFloat(bpv__Stamina__pf, 20.000000);
	bpv__Stamina__pf = bpv__CallFunc_Subtract_FloatFloat_ReturnValue__pf;
}
void AMage_C__pf3171751747::bpf__GetStamPercentage__pf(/*out*/ float& bpp__Perc__pf)
{
	ACharacter* bpv__CallFunc_GetPlayerCharacter_ReturnValue__pf{};
	AMage_C__pf3171751747* bpv__K2Node_DynamicCast_AsMage__pf{};
	bool bpv__K2Node_DynamicCast_bSuccess__pf{};
	float bpv__CallFunc_Divide_FloatFloat_ReturnValue__pf{};
	int32 CurrentState = 3;
	do
	{
		switch( CurrentState )
		{
		case 3:
			{
			}
		case 1:
			{
				bpv__CallFunc_GetPlayerCharacter_ReturnValue__pf = UGameplayStatics::GetPlayerCharacter(this, 0);
				bpv__K2Node_DynamicCast_AsMage__pf = Cast<AMage_C__pf3171751747>(bpv__CallFunc_GetPlayerCharacter_ReturnValue__pf);
				bpv__K2Node_DynamicCast_bSuccess__pf = (bpv__K2Node_DynamicCast_AsMage__pf != nullptr);;
				if (!bpv__K2Node_DynamicCast_bSuccess__pf)
				{
					CurrentState = 2;
					break;
				}
			}
		case 2:
			{
				float  __Local__15 = 0.000000;
				bpv__CallFunc_Divide_FloatFloat_ReturnValue__pf = FCustomThunkTemplates::Divide_FloatFloat(((IsValid(bpv__K2Node_DynamicCast_AsMage__pf)) ? (bpv__K2Node_DynamicCast_AsMage__pf->bpv__Stamina__pf) : (__Local__15)), 100.000000);
				bpp__Perc__pf = bpv__CallFunc_Divide_FloatFloat_ReturnValue__pf;
				CurrentState = -1;
				break;
			}
		default:
			break;
		}
	} while( CurrentState != -1 );
}
bool  AMage_C__pf3171751747::CanJumpInternal_Implementation() const
{
	return const_cast<AMage_C__pf3171751747*>(this)->bpf__CanJumpInternal__pf_Inner_0();
}
bool  AMage_C__pf3171751747::bpf__CanJumpInternal__pf_Inner_0()
{
	bool bpp__ReturnValue__pf{};
	bool bpv__CallFunc_CanJumpInternal_ReturnValue__pf{};
	bool bpv__CallFunc_Less_FloatFloat_ReturnValue__pf{};
	int32 CurrentState = 6;
	do
	{
		switch( CurrentState )
		{
		case 6:
			{
			}
		case 1:
			{
				bpv__CallFunc_CanJumpInternal_ReturnValue__pf = Super::CanJumpInternal_Implementation();
			}
		case 2:
			{
				if (!bpv__CallFunc_CanJumpInternal_ReturnValue__pf)
				{
					CurrentState = 4;
					break;
				}
			}
		case 3:
			{
				bpv__CallFunc_Less_FloatFloat_ReturnValue__pf = UKismetMathLibrary::Less_FloatFloat(bpv__Stamina__pf, 20.000000);
				if (!bpv__CallFunc_Less_FloatFloat_ReturnValue__pf)
				{
					CurrentState = 5;
					break;
				}
			}
		case 4:
			{
				bpp__ReturnValue__pf = false;
				CurrentState = -1;
				break;
			}
		case 5:
			{
				bpp__ReturnValue__pf = true;
				CurrentState = -1;
				break;
			}
		default:
			break;
		}
	} while( CurrentState != -1 );
	return bpp__ReturnValue__pf;
}
void AMage_C__pf3171751747::bpf__TakeForceFieldDamage__pf()
{
	ACharacter* bpv__CallFunc_GetPlayerCharacter_ReturnValue__pf{};
	AMage_C__pf3171751747* bpv__K2Node_DynamicCast_AsMage__pf{};
	bool bpv__K2Node_DynamicCast_bSuccess__pf{};
	float bpv__CallFunc_Subtract_FloatFloat_ReturnValue__pf{};
	int32 CurrentState = 3;
	do
	{
		switch( CurrentState )
		{
		case 3:
			{
			}
		case 1:
			{
				bpv__CallFunc_GetPlayerCharacter_ReturnValue__pf = UGameplayStatics::GetPlayerCharacter(this, 0);
				bpv__K2Node_DynamicCast_AsMage__pf = Cast<AMage_C__pf3171751747>(bpv__CallFunc_GetPlayerCharacter_ReturnValue__pf);
				bpv__K2Node_DynamicCast_bSuccess__pf = (bpv__K2Node_DynamicCast_AsMage__pf != nullptr);;
				if (!bpv__K2Node_DynamicCast_bSuccess__pf)
				{
					CurrentState = 2;
					break;
				}
			}
		case 2:
			{
				float  __Local__16 = 0.000000;
				bpv__CallFunc_Subtract_FloatFloat_ReturnValue__pf = UKismetMathLibrary::Subtract_FloatFloat(((IsValid(bpv__K2Node_DynamicCast_AsMage__pf)) ? (bpv__K2Node_DynamicCast_AsMage__pf->bpv__Health__pf) : (__Local__16)), 1.000000);
				if(IsValid(bpv__K2Node_DynamicCast_AsMage__pf))
				{
					bpv__K2Node_DynamicCast_AsMage__pf->bpv__Health__pf = bpv__CallFunc_Subtract_FloatFloat_ReturnValue__pf;
				}
				CurrentState = -1;
				break;
			}
		default:
			break;
		}
	} while( CurrentState != -1 );
}
void AMage_C__pf3171751747::__StaticDependencies_CommonAssets(TArray<FBlueprintDependencyData>& AssetsToLoad)
{
	FBlueprintDependencyData LocAssets[] =
	{
		FBlueprintDependencyData(TEXT("/Game/StarterContent/Props/MaterialSphere"), TEXT("MaterialSphere"), TEXT("/Script/Engine"), TEXT("StaticMesh")),
		FBlueprintDependencyData(TEXT("/Game/StarterContent/Materials/M_Concrete_Grime"), TEXT("M_Concrete_Grime"), TEXT("/Script/Engine"), TEXT("Material")),
		FBlueprintDependencyData(TEXT("/Game/StarterContent/Particles/P_Fire"), TEXT("P_Fire"), TEXT("/Script/Engine"), TEXT("ParticleSystem")),
		FBlueprintDependencyData(TEXT("/Game/StarterContent/Particles/P_Explosion"), TEXT("P_Explosion"), TEXT("/Script/Engine"), TEXT("ParticleSystem")),
		FBlueprintDependencyData(TEXT("/Engine/EngineFonts/Roboto"), TEXT("Roboto"), TEXT("/Script/Engine"), TEXT("Font")),
		FBlueprintDependencyData(TEXT("/Game/Mannequin/Character/Mesh/UE4_Mannequin_Skeleton"), TEXT("UE4_Mannequin_Skeleton"), TEXT("/Script/Engine"), TEXT("Skeleton")),
		FBlueprintDependencyData(TEXT("/Game/Mannequin/Animations/ThirdPersonJump_Start"), TEXT("ThirdPersonJump_Start"), TEXT("/Script/Engine"), TEXT("AnimSequence")),
		FBlueprintDependencyData(TEXT("/Game/Mannequin/Animations/ThirdPerson_Jump"), TEXT("ThirdPerson_Jump"), TEXT("/Script/Engine"), TEXT("AnimSequence")),
		FBlueprintDependencyData(TEXT("/Game/Mannequin/Animations/ThirdPersonJump_Loop"), TEXT("ThirdPersonJump_Loop"), TEXT("/Script/Engine"), TEXT("AnimSequence")),
		FBlueprintDependencyData(TEXT("/Game/Mannequin/Animations/ThirdPerson_IdleRun_2D"), TEXT("ThirdPerson_IdleRun_2D"), TEXT("/Script/Engine"), TEXT("BlendSpace1D")),
		FBlueprintDependencyData(TEXT("/Game/Mannequin/Character/Mesh/SK_Mannequin"), TEXT("SK_Mannequin"), TEXT("/Script/Engine"), TEXT("SkeletalMesh")),
	};
	for(auto& LocAsset : LocAssets) { AssetsToLoad.Add(LocAsset); } 
}
void AMage_C__pf3171751747::__StaticDependencies_DirectlyUsedAssets(TArray<FBlueprintDependencyData>& AssetsToLoad)
{
	__StaticDependencies_CommonAssets(AssetsToLoad);
}
void AMage_C__pf3171751747::__StaticDependenciesAssets(TArray<FBlueprintDependencyData>& AssetsToLoad)
{
	__StaticDependencies_CommonAssets(AssetsToLoad);
	FBlueprintDependencyData LocAssets[] =
	{
		FBlueprintDependencyData(TEXT("/Game/ThirdPersonCPP/Fireball"), TEXT("Fireball_C"), TEXT("/Script/CoreUObject"), TEXT("DynamicClass")),
		FBlueprintDependencyData(TEXT("/Game/ThirdPersonCPP/StarterContent/Textures/FireballExplosion"), TEXT("FireballExplosion_C"), TEXT("/Script/CoreUObject"), TEXT("DynamicClass")),
		FBlueprintDependencyData(TEXT("/Game/ThirdPersonCPP/Blueprints/inGameHUD"), TEXT("inGameHUD_C"), TEXT("/Script/CoreUObject"), TEXT("DynamicClass")),
		FBlueprintDependencyData(TEXT("/Game/Mannequin/Animations/ThirdPerson_AnimBP"), TEXT("ThirdPerson_AnimBP_C"), TEXT("/Script/CoreUObject"), TEXT("DynamicClass")),
	};
	for(auto& LocAsset : LocAssets) { AssetsToLoad.Add(LocAsset); } 
}
struct FRegisterHelper__AMage_C__pf3171751747
{
	FRegisterHelper__AMage_C__pf3171751747()
	{
		FConvertedBlueprintsDependencies::Get().RegisterClass(TEXT("/Game/ThirdPersonCPP/Blueprints/Mage"), &AMage_C__pf3171751747::__StaticDependenciesAssets);
	}
	static FRegisterHelper__AMage_C__pf3171751747 Instance;
};
FRegisterHelper__AMage_C__pf3171751747 FRegisterHelper__AMage_C__pf3171751747::Instance;
#ifdef _MSC_VER
#pragma warning (pop)
#endif
