#include <iostream>
using namespace std;


class Person {
private:
   string name_;
   int age_;
public:
   Person(const string& name, int age);
   void ShowPersonInfo();
};

Person::Person(const string& name, int age) {
   name_ = name;
   age_ = age;
}

class Student : public Person {
private:
   int studeni_id;
public:
   Student(int sid, const string& name, int age);
};

Student::Student(int sid, const string& name, int age) : Person(name, age) {
   studeni_id = sid;
}

void Person::ShowPersonInfo(void) {
   cout << name_ << "�� ���̴�" << age_ << "�� �Դϴ�." << endl;
}
int main(void)
{
   Student hong(201512340, "�浿", 25);
   hong.ShowPersonInfo();

   return 0;
}
// #include <iostream>
// #include <string>
// #include <vector>
// #include <WinSock2.h>
// #include <pthread.h>
// #pragma comment (lib , "ws2_32.lib")
// using namespace std;

// bool sendThreadStart;
// bool recvThreadStart;

// void stillReceiving(SOCKET* recvSocket, char* buffer, string* rMessage) {
// 	int messageLength;
// 	while (TRUE)
// 	{
// 		messageLength = recv(*recvSocket, buffer, strlen(buffer), 0);
// 		buffer[messageLength] = 0;
// 		*rMessage = buffer;
// 		cout << *rMessage << endl;
// 		sendThreadStart = TRUE;
// 	}
// }

// void stillSending(SOCKET* sendSocket, string* sMessage)
// {
// 	int sendCheck;
// 	while (TRUE)
// 	{
// 		try
// 		{
// 			if (sendThreadStart) {
// 				sendCheck = send(*sendSocket, (*sMessage).c_str(), (*sMessage).length(), 0);
// 				sendThreadStart = FALSE;
// 			}
// 		}
// 		catch (const invalid_argument& ex)
// 		{
// 			cerr << "Invalid argument while converting string to number" << endl;
// 			cerr << "Error : " << ex.what() << endl;
// 			break;
// 		}
// 		catch (const out_of_range& ex)
// 		{
// 			cerr << "Invalid argument while converting string to number" << endl;
// 			cerr << "Error : " << ex.what() << endl;
// 			break;
// 		}
// 		catch (const exception& expn)
// 		{
// 			cout << expn.what() << endl;
// 			break;
// 		}
// 	}
// }

// int main(void)
// {
// 	WSADATA wsaData;
// 	SOCKADDR_IN serverAdress, clientAdress;

// 	int err = WSAStartup(MAKEWORD(2, 2), &wsaData);

// 	if (err != 0) {
// 		cout << "WSAStartup error " << WSAGetLastError() << endl;
// 		WSACleanup();
// 		return false;
// 	}

// 	serverAdress.sin_family = AF_INET; // AF_INET�� ����??
// 	serverAdress.sin_port = htons(11235);
// 	serverAdress.sin_addr.s_addr = inet_addr("127.0.0.1"); // s_addr�� �׳� ������ ��?

// 	SOCKET serverSocket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);

// 	if (serverSocket == INVALID_SOCKET)
// 	{
// 		cout << "Socket Error" << WSAGetLastError() << endl;
// 		WSACleanup();
// 		return false; // ���� ���� ���н� ����
// 	}

// 	if (bind(serverSocket, reinterpret_cast<SOCKADDR*> (&serverAdress), sizeof(serverAdress)))
// 	{
// 		// reinterpret_cast���� cast�� ����?
// 		cout << "Binding failed. Error code : " << WSAGetLastError() << endl;
// 		WSACleanup();
// 		return false;
// 	}

// 	cout << "client�� ��ٸ��ϴ�." << endl;

// 	listen(serverSocket, 5); // backlog(5)�� ����?
// 	int xx = sizeof(clientAdress);
// 	SOCKET chatSocket = accept(serverSocket, reinterpret_cast<SOCKADDR*> (&clientAdress), &xx); // bind������ �׳� sizeof ������ �� ��� &(�ּҰ�)����?
// 	cout << "Connection Complete " << "���ο� Socket�� " << chatSocket << endl;
// 	SOCKET* chatSocketPtr = &chatSocket;


// 	int receiveNumber;
// 	char communicationBuffer[8192]; // 1024 * 8 byte
// 	int iRand;
// 	int bytesSent;
// 	int i = 0;
// 	string recvMessage;
// 	string* recvMessagePtr = &recvMessage;

// 	thread recvData(stillReceiving, chatSocketPtr, communicationBuffer, recvMessagePtr);
// 	thread sendData(stillSending, chatSocketPtr, recvMessagePtr);
// 	while (TRUE) {

// 		if (sendThreadStart == FALSE) {
// 			SuspendThread(sendData.native_handle());
// 			break;
// 		}
// 		else {
// 			ResumeThread(sendData.native_handle());
// 		}
// 	}

// 	/*recvData.detach();
// 	sendData.detach();*/
// 	recvData.join();
// 	sendData.join();

// 	//while (TRUE)
// 	//{
// 	//	receiveNumber = recv(chatSocket, communicationBuffer, 100, 0); // flag�� ����?
// 	//	communicationBuffer[receiveNumber] = 0;
// 	//	cout << "received Message from Client : " << communicationBuffer << endl;
// 	//	if (receiveNumber <= 0) { cout << "Got nothing" << endl; break; }

// 	//	string sNumber = communicationBuffer;

// 	//	try
// 	//	{
// 	//		bytesSent = send(chatSocket, sNumber.c_str(), sNumber.length(), 0);
// 	//	}
// 	//	catch (const invalid_argument& ex)
// 	//	{
// 	//		cerr << "Invalid argument while converting string to number" << endl;
// 	//		cerr << "Error : " << ex.what() << endl;
// 	//		break;
// 	//	}
// 	//	catch (const out_of_range& ex)
// 	//	{
// 	//		cerr << "Invalid argument while converting string to number" << endl;
// 	//		cerr << "Error : " << ex.what() << endl;
// 	//		break;
// 	//	}
// 	//	catch (const exception& expn)
// 	//	{
// 	//		cout << expn.what() << endl;
// 	//	}
// 	//}

// 	closesocket(serverSocket);
// 	WSACleanup();

// 	return 0;
// }