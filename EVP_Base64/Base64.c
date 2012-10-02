#include <stdio.h> 
#include <string.h> 
#include <openssl/evp.h> 
#include <openssl/x509.h> 
 
//Base64���� 
void tEVP_Encode() 
{ 
	EVP_ENCODE_CTX ctx;				//EVP����ṹ�� 
	unsigned char in[1024];			//�������ݻ����� 
	int inl;						//�������ݳ��� 
	char out[2048]={0};				//������ݻ����� 
	int outl;						//������ݳ��� 
	FILE *infp;						//�����ļ���� 
	FILE *outfp;					//����ļ���� 
 
	infp = fopen("original","rb");//�򿪴�������ļ� 
	if(infp == NULL) 
	{ 
		printf("Open File \"Test.dat\"  for Read Err.\n"); 
		return; 
	} 
	 
	outfp = fopen("Encryption","w");//�򿪱���󱣴���ļ� 
	if(outfp == NULL) 
	{ 
		printf("Open File \"original\" For Write Err.\n"); 
		return; 
	} 
	EVP_EncodeInit(&ctx);//Base64�����ʼ�� 
	printf("file\"original\" Base64 encoded\n"); 
	//ѭ����ȡԭ�ģ�������EVP_EncodeUpdate����Base64���� 
	while(1) 
	{ 
		inl = fread(in,1,1024,infp); 
		if(inl <= 0) 
			break; 
		EVP_EncodeUpdate(&ctx,out,&outl,in,inl);//���� 
		fwrite(out,1,outl,outfp);//������������ļ� 
		printf("%s",out); 
	}  
	EVP_EncodeFinal(&ctx,out,&outl);//��ɱ��룬����������ݡ� 
	fwrite(out,1,outl,outfp); 
	printf("%s",out); 
	fclose(infp); 
	fclose(outfp);	 
	printf("To file\"original\" complete to encode by Base64 and save to \"Encryption\"file.\n\n\n"); 
} 
 
//Base64���� 
void tEVP_Decode() 
{ 
	EVP_ENCODE_CTX ctx;				//EVP����ṹ�� 
	char in[1024];					//�������ݻ����� 
	int inl;						//�������ݳ��� 
	unsigned char out[1024];		//������ݻ����� 
	int outl;						//������ݳ��� 
	FILE *infp;						//�����ļ���� 
	FILE *outfp;					//����ļ���� 
	 
	infp = fopen("Encryption","r");//�򿪴�������ļ� 
	if(infp == NULL) 
	{ 
		printf("Open File \"Encryption\"  for Read Err.\n"); 
		return; 
	} 
	outfp = fopen("Decryption","wb");//�򿪽���󱣴���ļ� 
	if(outfp == NULL) 
	{ 
		printf("Open File \"Encryption\" For Write Err.\n"); 
		return; 
	} 
	EVP_DecodeInit(&ctx);//Base64�����ʼ�� 
	printf("Starting to decode to \"Encryption\" by Base64...\n\n"); 
	//ѭ����ȡԭ�ģ�������EVP_DecodeUpdate����Base64���� 
	while(1) 
	{ 
		inl = fread(in,1,1024,infp); 
		if(inl <= 0) 
			break; 
		EVP_DecodeUpdate(&ctx,out,&outl,in,inl);//Base64���� 
		fwrite(out,1,outl,outfp);//������ļ� 
	}  
	EVP_DecodeFinal(&ctx,out,&outl);//��ɽ��룬����������ݡ� 
	fwrite(out,1,outl,outfp); 
	fclose(infp); 
	fclose(outfp);	 
	printf("To file\"original\" complete to decode by Base64 and save to\"Decryption\"\n\n\n"); 
	 
} 
  
int main() 
{ 
  
	tEVP_Encode(); 
	tEVP_Decode(); 
	 
	return 0; 
}
