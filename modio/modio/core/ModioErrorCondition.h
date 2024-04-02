/* 
 *  Copyright (C) 2021 mod.io Pty Ltd. <https://mod.io>
 *  
 *  This file is part of the mod.io SDK.
 *  
 *  Distributed under the MIT License. (See accompanying file LICENSE or 
 *   view online at <https://github.com/modio/modio-sdk/blob/main/LICENSE>)
 *  
 */

#pragma once

#include "ModioErrorCondition.generated.h"

UENUM(BlueprintType)
enum class EModioErrorCondition: uint8
{
	NoError = 0,
	NetworkError = 2 UMETA(ToolTip="When this condition is true, the error code represents a connection or HTTP error between the client and the mod.io server.") ,
	ConfigurationError = 3 UMETA(ToolTip="When this condition is true, the error code indicates the SDK's configuration is not valid - the game ID or API key are incorrect or the game has been deleted.") ,
	InvalidArgsError = 4 UMETA(ToolTip="When this condition is true, the error code indicates the arguments passed to the function have failed validation or were otherwise invalid.") ,
	FilesystemError = 5 UMETA(ToolTip="When this condition is true, the error code indicates a permission or IO error when accessing local filesystem data.") ,
	InternalError = 6 UMETA(ToolTip="When this condition is true, the error code represents an internal SDK error - please inform mod.io of the error code value.") ,
	ApiErrorRefSuccess = 7 UMETA(ToolTip="When this condition is true, the error ref returned by the API indicates an implicit success because the operation has already been performed (ie a no-op is success).") ,
	EntityNotFoundError = 12 UMETA(ToolTip="When this condition is true, the error code indicates that a specified game, mod, user, media file or mod file was not found.") ,
	UserTermsOfUseError = 13 UMETA(ToolTip="When this condition is true, the error code indicates that the user has not yet accepted the mod.io Terms of Use.") ,
	SubmitReportError = 14 UMETA(ToolTip="When this condition is true, the error code indicates that a report for the specified content could not be submitted.") ,
	UserNotAuthenticatedError = 15 UMETA(ToolTip="When this condition is true, the error code indicates that a user is not authenticated.") ,
	SDKNotInitialized = 16 UMETA(ToolTip="When this condition is true, the error code indicates that the SDK has not been initialized.") ,
	UserAlreadyAuthenticatedError = 17 UMETA(ToolTip="When this condition is true, the error code indicates that the user is already authenticated.") ,
	SystemError = 18 UMETA(ToolTip="When this condition is true, the error code indicates that a low-level system error occurred outside of mod.io SDK control.") ,
	OperationCanceled = 19 UMETA(ToolTip="When this condition is true, the error code indicates that the asynchronous operation was cancelled before it completed.") ,
	ModManagementDisabled = 20 UMETA(ToolTip="When this condition is true, the error code indicates that Mod Management has not been enabled.") ,
	RateLimited = 21 UMETA(ToolTip="Too many requests made to the mod.io API within the rate-limiting window. Please wait and try again.") ,
	ModBeingProcessed = 22 UMETA(ToolTip="The specified mod's files are currently being updated by the SDK. Please try again later.") ,
	InsufficientSpace = 23 UMETA(ToolTip="There is insufficient space to install the mod. Please free up space and try again.") ,
	SDKAlreadyInitialized = 24 UMETA(ToolTip="When this condition is true, the error code indicates that the SDK has already been initialized.") ,
	ModManagementAlreadyEnabled = 25 UMETA(ToolTip="When this condition is true, the error code indicates that Mod Management has already been enabled.") ,
	InsufficientPermissions = 26 UMETA(ToolTip="When this condition is true, the error code indicates that the current user does not have the required permissions for this operation.") ,
	EmailLoginCodeInvalid = 27 UMETA(ToolTip="The email login code is incorrect or has expired.") ,
	AlreadySubscribed = 28 UMETA(ToolTip="The specified mod is already subscribed to.") ,
	InstallOrUpdateCancelled = 29 UMETA(ToolTip="The current mod installation or update was cancelled.") ,
	UploadCancelled = 30 UMETA(ToolTip="The current modfile upload was cancelled.") ,
};
