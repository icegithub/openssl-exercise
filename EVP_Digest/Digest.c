#include <stdio.h>
#include <string.h>
//#include <windows.h>
#include <openssl/evp.h>
void tDigest()
{
	unsigned char md_value[EVP_MAX_MD_SIZE];	//保存输出的摘要值的数组
	int md_len, i;
	EVP_MD_CTX mdctx;							//EVP消息摘要结构体
	char msg1[] = "Test Message1";				//待计算摘要的消息1	
	char msg2[] = "Test Message2";				//待计算摘要的消息2
	
	EVP_MD_CTX_init(&mdctx);					//初始化摘要结构体 
	EVP_DigestInit_ex(&mdctx, EVP_sha1(), NULL);	//设置摘要算法和密码算法引擎，这里密码算法使用MD5，算法引擎使用OpenSSL默认引擎即软算法
	EVP_DigestUpdate(&mdctx, msg1, strlen(msg1));//调用摘要UpDate计算msg1的摘要
	EVP_DigestUpdate(&mdctx, msg2, strlen(msg2));//调用摘要UpDate计算msg2的摘要	
	EVP_DigestFinal_ex(&mdctx, md_value, &md_len);//摘要结束，输出摘要值	
	EVP_MD_CTX_cleanup(&mdctx);						//释放内存
	
	printf("Original data %s and %s's digest:\n",msg1,msg2);
	for(i = 0; i < md_len; i++) 
	{
		printf("0x%02x ", md_value[i]);
	}
	printf("\n");
}
int main()
{ 
	OpenSSL_add_all_algorithms();
	tDigest();
	return 0;
}
