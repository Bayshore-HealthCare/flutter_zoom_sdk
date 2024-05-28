//
//  MobileRTCMeetingChat.h
//  MobileRTC
//
//  Created by Zoom Video Communications on 2017/9/15.
//  Copyright © 2019年 Zoom Video Communications, Inc. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <MobileRTC/MobileRTCConstants.h>

@class MobileRTCMeetingChat;
/*!
 @brief Chat message builder to create ChatMsgInfo objects.
 */
@interface MobileRTCMeetingChatBuilder : NSObject
/*!
 @brief Set chat message content.
 @param content The chat message’s content.
 */
- (MobileRTCMeetingChatBuilder * _Nullable)setContent:(NSString * _Nullable)content;
/*!
 @brief Set who will receive the chat message.
 @param receiver Specify the user ID to receive the chat message. The message is sent to all participants when the value is zero (0).
 */
- (MobileRTCMeetingChatBuilder * _Nullable)setReceiver:(NSInteger)receiver;
/*!
 @brief Set the ID of the thread where the message will be posted.
 @param threadId Specify the thread ID.
 */
- (MobileRTCMeetingChatBuilder * _Nullable)setThreadId:(NSString * _Nullable)threadId;
/*!
 @brief Set the chat message type.
 @param type The chat message’s type.
 */
- (MobileRTCMeetingChatBuilder * _Nullable)setMessageType:(MobileRTCChatMessageType)type;
/*!
 @brief Set the chat message content quote style and position.
 @param start The segment start position.
 @param end The segment end position.
 */
- (MobileRTCMeetingChatBuilder * _Nullable)setQuotePosition:(NSInteger)start end:(NSInteger)end;
/*!
 @brief Build chat message entity.
 @return If the function succeeds, the return value is the message detail information.
 */
- (MobileRTCMeetingChat * _Nullable)build;

@end

/*!
 @brief for rich text solution, the specify rich text offset information.
 */
@interface MobileRTCRichTextStyleOffset : NSObject
/*!
 @brief Get a certain rich-text style’s start position.
 */
@property (nonatomic, assign) NSInteger positionStart;
/*!
 @brief Get a certain rich-text style’s end position.
 */
@property (nonatomic, assign) NSInteger positionEnd;
/*!
 @brief Get a certain rich-text style’s supplementary information.
 @warning If the style is TextStyle_FontSize, possible return values are FontSize_Small, FontSize_Medium, or FontSize_Large.
 If style is TextStyle_Paragraph, possible return values are as follows Paragraph_H1, Paragraph_H2, or Paragraph_H3.
 If the style is TextStyle_FontColor, or TextStyle_BackgroundColor, possible return values are hex string representing standard RGB data.
 */
@property (nonatomic, copy) NSString * _Nullable reserve;
@end

/*!
 @brief for rich text solution, the specify text styple information.
 */
@interface MobileRTCRichTextStyleItem : NSObject
/*!
 @brief Get the rich text type of a portion of the current message.
 */
@property (nonatomic, assign) MobileRTCRichTextStyle textStyle;
/*!
 @brief Get the current message’s rich text position info list of a certain style.
 */
@property (nonatomic, copy) NSArray <MobileRTCRichTextStyleOffset *>* _Nullable textStyleOffsetList;
@end

/*!
 @brief Retrieve the meeting chat data.
 @warning The function is optional.
 */
@interface MobileRTCMeetingChat : NSObject

/*!
 @brief The message ID.
 */
@property (nonatomic, copy) NSString * _Nullable chatId;
/*!
 @brief The ID of user who sends message.
 */
@property (nonatomic, copy) NSString * _Nullable senderId;
/*!
 @brief The screen name of user who sends message.
 */
@property (nonatomic, copy) NSString * _Nullable senderName;
/*!
 @brief The ID of user who receives message.
 */
@property (nonatomic, copy) NSString * _Nullable receiverId;
/*!
 @brief The screen name of user who receives message.
 */
@property (nonatomic, copy) NSString * _Nullable receiverName;
/*!
 @brief The message content.
 */
@property (nonatomic, copy) NSString * _Nullable content;
/*!
 @brief The message timestamps.
 */
@property (nonatomic, retain) NSDate *_Nullable date;

/*!
 @brief The Chat message type.
 */
@property (nonatomic, assign) MobileRTCChatMessageType chatMessageType;

/*!
 @brief Whether the message is sent by the user himself or not.
 */
@property (nonatomic, assign) BOOL isMyself;
/*!
 @brief Whether the message is private or not.
 */
@property (nonatomic, assign) BOOL isPrivate;
/*!
 @brief Whether the message is send to all or not.
 */
@property (nonatomic, assign) BOOL isChatToAll;
/*!
 @brief Whether the message is send to all panelist or not.
 */
@property (nonatomic, assign) BOOL isChatToAllPanelist;
/*!
 @brief Whether the message is send to waiting room or not.
 */
@property (nonatomic, assign) BOOL isChatToWaitingroom;
/*!
@brief Determine if the current message is a comment replying to another message.
 */
@property (nonatomic, assign) BOOL isComment;
/*!
@brief Determine if the current message is part of a message thread. and can be directly replied to.
*/
@property (nonatomic, assign) BOOL isThread;
/*!
@brief Get the current message’s chat message font style list.
*/
@property (nonatomic, copy) NSArray <MobileRTCRichTextStyleItem *>* _Nullable textStyleItemList;
/*!
@brief Get the current message’s thread ID.
*/
@property (nonatomic, copy) NSString * _Nullable threadID;
@end
