#include "TestStringBuilder.h"
#include "MyStringBuilder.h"
#include <iostream>
using namespace std;
void TestStringBuilder::AppendTest() {
	MyStringBuilder builder;
	string s1 = "sentence1";
	string s2 = "phrase2";
	string s3 = "thirdSentence";
	builder.Append(s1);
	builder.Append(s2);
	builder.Append(s3);
	string insertedS1 = builder._root->GetValue();
	string insertedS2 = builder._root->GetNext()->GetValue();
	string insertedS3 = builder._root->GetNext()->GetNext()->GetValue();
	if (builder._size == s1.length() + s2.length() + s3.length()
		&& insertedS1 == "sentence1" &&
		insertedS2 == "phrase2" &&
		insertedS3 == "thirdSentence") {
		cout << "Test succeeded" << endl;
	}
	else {
		cout << "Test Failed" << endl;
	}
}
void TestStringBuilder::ClearTest() {
	MyStringBuilder builder;
	builder.Append("sentence1");
	builder.Append("phrase2");
	builder.Append("thirdSentence");
	builder.Clear();
	string res = builder.ToString();
	if (res.empty()) {
		cout << "Test suceeded" << endl;
	}
	else {
		cout << "Test failed" << endl;
	}
}
void TestStringBuilder::ToStringTest() {
	MyStringBuilder builder;
	builder.Append("sentence1");
	builder.Append("phrase2");
	builder.Append("thirdSentence");
	string res = builder.ToString();
	if (res == "sentence1phrase2thirdSentence") {
		cout << "Test succeeded" << endl;
	}
	else {
		cout << "Test Failed" << endl;
	}
}
void TestStringBuilder::RunAllTests() {
	cout << "AppendTest" << endl;
	AppendTest();
	cout << "ClearTest" << endl;
	ClearTest();
	cout << "ToStringTest" << endl;
	ToStringTest();
}