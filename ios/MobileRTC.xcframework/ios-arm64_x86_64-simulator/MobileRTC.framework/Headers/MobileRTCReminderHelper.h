//
//  MobileRTCReminderHelper.h
//  MobileRTC
//
//  Created by Zoom on 3/27/23.
//  Copyright © 2023 Zoom Video Communications, Inc. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

@class MobileRTCReminderContent;
@class MobileRTCReminderHandler;

/**
 * @brief Reminder callback event.
 */
@protocol MobileRTCReminderDelegate <NSObject>
@optional

/**
 * @brief Callback event when the reminder dialog show.
 * @param content the detail content in the reminder dialog.
 * @param handler the helper to handle the reminder dialog.
 */
- (void)onReminderNotify:(MobileRTCReminderContent * _Nullable)content handle:(MobileRTCReminderHandler * _Nullable)handler;

@end

/**
 * @brief The reminder dialog content.
 */
@interface MobileRTCReminderContent : NSObject

/**
 *  the type of the reminder.
 */
@property (nonatomic, assign) MobileRTCReminderType type;

/**
 * the title of the reminder dialog.
 */
@property (nonatomic, copy, nullable) NSString *title;

/**
 * the detail content of the reminder dialog.
 */
@property (nonatomic, copy, nullable) NSString *content;

/**
 * whether block the user join or stay in the meeting.
 */
@property (nonatomic, assign) BOOL isBlock;

/**
 * Get the type of the action which user should take after receiving this reminder content.
 */
@property (nonatomic, assign) MobileRTCReminderActionType actionType;

/**
 * Get a list of reminder’s type.
 * @return List of the reminder’s type.
 */
- (NSArray<NSNumber*>*_Nonnull)getMultiReminderTypes;

@end

/**
 * @brief The interface to handle the reminder dialog.
 */
@interface MobileRTCReminderHandler : NSObject
/**
 * accept the reminder.
 */
- (MobileRTCSDKError)accept;

/**
 * declined the reminder.
 */
- (MobileRTCSDKError)declined;

/**
 * ignore the reminder.
 */
- (MobileRTCSDKError)ignore;

@end


@interface MobileRTCReminderHelper : NSObject

/**
 * @brief Callback to receive reminder events.
 */
@property (weak, nonatomic) id<MobileRTCReminderDelegate> _Nullable reminderDelegate;

@end


