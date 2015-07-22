//
//  GBAlipayConfig.h
//  支付宝极简支付
//
//  Created by marks on 15/6/3.
//  Copyright (c) 2015年 zhangguobing. All rights reserved.
//

#ifndef ________GBAlipayConfig_h
#define ________GBAlipayConfig_h

#import <AlipaySDK/AlipaySDK.h>     // 导入AlipaySDK
#import "Order.h"                   // 导入订单类
#import "DataSigner.h"              // 生成signer的类
/**
 *  合作身份者id，以2088开头的16位纯数字
 */
#define PartnerID @"2088511933544308"
/**
 *  收款支付宝账号
 */
#define SellerID  @"yingtehua8@sina.com"

/**
 *  安全校验码（MD5）密钥，以数字和字母组成的32位字符
 */
#define MD5_KEY @"1g81z5tgu3o2yst4mqm6n838dxe5cw1a"
/**
 *  appSckeme:应用注册scheme,在Info.plist定义URLtypes，处理支付宝回调
 */
#define kAppScheme @"KSFCAlipay2015"
/**
 *  支付宝服务器主动通知商户交易是否成功 网站里指定的页面 http 路径。非必需
 */
#define kNotifyURL @""
/**
 *  商户私钥，自助生成
 */
#define PartnerPrivKey @"MIICdQIBADANBgkqhkiG9w0BAQEFAASCAl8wggJbAgEAAoGBAL0M8jaJCm9bMb7PjgI0wR9+mpzWTcNTwTyYBEXmrJg3MjRVluUezDjQhQBSrgaMTeM40cz+1Nt/f1OlS/vB9PzGSF+MDty6zS0NQEEvVjUUge7PsOtbPDIEmuPppKIj4wETfavaZt7j4/kVuABDC2P1DpPRP686dJsNTkSO5qrNAgMBAAECgYApxEVy9P3gMkagQFzAcgVEvwTLp7EQeV2U1IUFKHxzOKaX11z6C77UwoTP2HRoL/E5RSFc5+QBBn8L7NYHrgdAu4L5Kl048saM53QyXJviQs7lgxDSBbo+EHDY9OJJsVRalpqKSirgBZmce/M4/tNhDxUfV5yXvxOC43JEr92UIQJBAPXbahDDMN+D0MqG1y0zPyU5bJwopXsSLIxpqp4vRmHokMxlber5HGMgSSnVQ9x9j974G1RSamqV34xwnqPzIlUCQQDE2ZPgtKd9Te19kGpmmCs64iqlkUVabAuKI8wMyx4hGZx6/EpeufFiTpF3F3YDN37JOenBefLL9UIkrOrjXI6ZAkBmpX75FKV5DG3FwNph0r2QaxM/d3DvmzziOtOzS4WVJyYdUFO+ANerQzWIs7OrgPjqXKf8YpRvf7dfyT1SshYpAkAhj0qDw6jOVwvHHWjWZtjv6AEHSxX8zXDGM0YlZDeVww0Hdp2jOqYpcWWhXRGUiNCHs+TjREwdc4m8QPKmom/5AkAYGRw6TLB/XWfEvlGLMHMmbZWMXDBdBmlIN+JK2oRjIoTryG35KlXzAHWcAq2xVhvCd6gJjz9arUmqewOLBMWn"

/**
 *  支付宝公钥
 */
#define AlipayPubKey   @"MIGfMA0GCSqGSIb3DQEBAQUAA4GNADCBiQKBgQCnxj/9qwVfgoUh/y2W89L6BkRAFljhNhgPdyPuBV64bfQNN1PjbCzkIM6qRdKBoLPXmKKMiFYnkd6rAoprih3/PrQEB/VsW8OoM8fxn67UDYuyBTqA23MML9q1+ilIZwBC2AQ2UBVOrFXfFl75p6/B5KsiNG9zpgmLCUYuLkxpLQIDAQAB"

#endif

