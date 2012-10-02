#include <stdio.h>
#include <string.h>
//#include <windows.h>
#include <openssl/evp.h>
void tDigest()
{
	unsigned char md_value[EVP_MAX_MD_SIZE];	//���������ժҪֵ������
	int md_len, i;
	EVP_MD_CTX mdctx;							//EVP��ϢժҪ�ṹ��
	char msg1[] = "Test Message1";				//������ժҪ����Ϣ1	
	char msg2[] = "Test Message2";				//������ժҪ����Ϣ2
	
	EVP_MD_CTX_init(&mdctx);					//��ʼ��ժҪ�ṹ�� 
	EVP_DigestInit_ex(&mdctx, EVP_sha1(), NULL);	//����ժҪ�㷨�������㷨���棬���������㷨ʹ��MD5���㷨����ʹ��OpenSSLĬ�����漴���㷨
	EVP_DigestUpdate(&mdctx, msg1, strlen(msg1));//����ժҪUpDate����msg1��ժҪ
	EVP_DigestUpdate(&mdctx, msg2, strlen(msg2));//����ժҪUpDate����msg2��ժҪ	
	EVP_DigestFinal_ex(&mdctx, md_value, &md_len);//ժҪ���������ժҪֵ	
	EVP_MD_CTX_cleanup(&mdctx);						//�ͷ��ڴ�
	
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
