#include "stdafx.h"
#include <stdint.h>
#include <string>
#include<iostream>
#pragma once
#include "Form2.h"
#include "udp.h"
int value=0;


#define RECEIVE_IP          "127.0.0.1"
unsigned short ReceivingPort = 8005;

UdpInSocket inSocket_Ownship1(RECEIVE_IP,  ReceivingPort);    


namespace Crypto {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Text;
	using namespace System::IO;
	using namespace System::Security::Cryptography;

	/*  Encryption using RSA Algortihm  */ 
	array<Byte>^ RSAEncrypt( array<Byte>^DataToEncrypt, RSAParameters RSAKeyInfo, bool DoOAEPPadding )
		{
		try
			{
				//Creating a new instance of RSACryptoStream Memory.
				RSACryptoServiceProvider^ RSA = gcnew RSACryptoServiceProvider;

				RSA->ImportParameters( RSAKeyInfo );

				array<Byte>^ encryptedData = RSA->Encrypt( DataToEncrypt, DoOAEPPadding );
				delete RSA;
				return encryptedData;
			}
				
		 catch ( CryptographicException^ e ) 
			{
				 Console::WriteLine( e->Message );
				 return nullptr;
			}
		}


	/*  Decryption using RSA Algortihm  */ 
	array<Byte>^ RSADecrypt( array<Byte>^DataToDecrypt, RSAParameters RSAKeyInfo, bool DoOAEPPadding )
		{
			try
				{
					//Creating a new instance of RSACryptoStream Memory.
					RSACryptoServiceProvider^ RSA = gcnew RSACryptoServiceProvider;
					RSA->ImportParameters( RSAKeyInfo );

					array<Byte> ^decryptedData = RSA->Decrypt( DataToDecrypt, DoOAEPPadding );
					delete RSA;
					return decryptedData;
				}
   
			catch ( CryptographicException^ e ) 
				{
					Console::WriteLine( e );
					return nullptr;
				}

		}

	/*  Encryption using DES Algortihm  */ 
	array<Byte>^ EncryptTextToMemory( String^ Data, array<Byte>^Key, array<Byte>^IV )
		{
			try
				{

			      MemoryStream^ mStream = gcnew MemoryStream;
				  //Creating a new instance of CryptoStream Memory.
			      CryptoStream^ cStream = gcnew CryptoStream( mStream,(gcnew DESCryptoServiceProvider)->CreateEncryptor( Key, IV ),CryptoStreamMode::Write );

				  array<Byte>^toEncrypt = (gcnew ASCIIEncoding)->GetBytes( Data );

				  cStream->Write( toEncrypt, 0, toEncrypt->Length );
				  cStream->FlushFinalBlock();

				  array<Byte>^ret = mStream->ToArray();

				 cStream->Close();
			     mStream->Close();
				 return ret;
			   }
			catch ( CryptographicException^ e ) 
			   {
				 Console::WriteLine( "A Cryptographic error occurred: {0}", e->Message );
				 return nullptr;
			   }
		}

	/*  Decryption using DES Algortihm  */ 
	array<Byte>^ DecryptTextFromMemory( array<Byte>^Data, array<Byte>^Key, array<Byte>^IV )
	{
		try
			{

				 MemoryStream^ msDecrypt = gcnew MemoryStream( Data );
				 //Creating a new instance of CryptoStream Memory.
				 CryptoStream^ csDecrypt = gcnew CryptoStream( msDecrypt,(gcnew DESCryptoServiceProvider)->CreateDecryptor( Key, IV ),CryptoStreamMode::Read );
				 array<Byte>^fromEncrypt = gcnew array<Byte>(Data->Length);

				 csDecrypt->Read( fromEncrypt, 0, fromEncrypt->Length );
				 return fromEncrypt;
			}
		catch ( CryptographicException^ e ) 
			{
				 Console::WriteLine( "A Cryptographic error occurred: {0}", e->Message );
				 return nullptr;
			}
	}


	public ref class Form1 : public System::Windows::Forms::Form
	{
	public:
		// All Variable Declaration.
		String^ cipherdata;
		String^ desdata;
		array<Byte>^ Final;
		array<Byte>^ cipherbytes;
		array<Byte>^ plainbytes;
		array<Byte>^ plainbytes2;
		array<Byte>^ plainkey;
		array<Byte>^ data;
		array<Byte>^ cdata;
		array<Byte>^ rbytes;
		array<Byte>^ descipher;
		SymmetricAlgorithm^ desObj;
		RSACryptoServiceProvider^ rsaObj;


	private: System::Windows::Forms::PictureBox^  pictureBox1;
	
	public: 

		

	public:
		Form1(void)
		{
			InitializeComponent();
			// Intialization of AES Algorithm Object.
			desObj = Rijndael::Create();

		}

	


	protected:
		~Form1()
		{
			if (components)
			{
				delete components;
			}
		}

	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::Button^  button2;
	private: System::Windows::Forms::TextBox^  textBox1;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::GroupBox^  groupBox1;
	private: System::Windows::Forms::RadioButton^  radioButton3;
	private: System::Windows::Forms::RadioButton^  radioButton2;
	private: System::Windows::Forms::RadioButton^  radioButton1;
	private: System::Windows::Forms::TextBox^  textBox2;
	private: System::Windows::Forms::Label^  label2;

	protected: 

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(Form1::typeid));
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->radioButton3 = (gcnew System::Windows::Forms::RadioButton());
			this->radioButton2 = (gcnew System::Windows::Forms::RadioButton());
			this->radioButton1 = (gcnew System::Windows::Forms::RadioButton());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->groupBox1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox1))->BeginInit();
			this->SuspendLayout();
			// 
			// button1
			// 
			this->button1->Font = (gcnew System::Drawing::Font(L"Georgia", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->button1->Location = System::Drawing::Point(92, 401);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(154, 58);
			this->button1->TabIndex = 0;
			this->button1->Text = L"ENCRYPT";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &Form1::button1_Click);
			// 
			// button2
			// 
			this->button2->Font = (gcnew System::Drawing::Font(L"Georgia", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->button2->Location = System::Drawing::Point(580, 401);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(152, 58);
			this->button2->TabIndex = 1;
			this->button2->Text = L"SEND";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &Form1::button2_Click);
			// 
			// textBox1
			// 
			this->textBox1->BackColor = System::Drawing::SystemColors::Window;
			this->textBox1->Font = (gcnew System::Drawing::Font(L"Georgia", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->textBox1->Location = System::Drawing::Point(217, 41);
			this->textBox1->Multiline = true;
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(557, 59);
			this->textBox1->TabIndex = 2;
			this->textBox1->TextChanged += gcnew System::EventHandler(this, &Form1::textBox1_TextChanged);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Georgia", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(28, 60);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(127, 16);
			this->label1->TabIndex = 3;
			this->label1->Text = L"Enter the Message :";
			// 
			// groupBox1
			// 
			this->groupBox1->Controls->Add(this->radioButton3);
			this->groupBox1->Controls->Add(this->radioButton2);
			this->groupBox1->Controls->Add(this->radioButton1);
			this->groupBox1->Font = (gcnew System::Drawing::Font(L"Georgia", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->groupBox1->Location = System::Drawing::Point(312, 124);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(383, 145);
			this->groupBox1->TabIndex = 4;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"Select Encryption Method (Signature)";
			// 
			// radioButton3
			// 
			this->radioButton3->AutoSize = true;
			this->radioButton3->Location = System::Drawing::Point(33, 100);
			this->radioButton3->Name = L"radioButton3";
			this->radioButton3->Size = System::Drawing::Size(285, 19);
			this->radioButton3->TabIndex = 6;
			this->radioButton3->TabStop = true;
			this->radioButton3->Text = L"Rivest Shamir Adleman Cryptosystem (RSA)";
			this->radioButton3->UseVisualStyleBackColor = true;
			this->radioButton3->CheckedChanged += gcnew System::EventHandler(this, &Form1::radioButton3_CheckedChanged);
			// 
			// radioButton2
			// 
			this->radioButton2->AutoSize = true;
			this->radioButton2->Location = System::Drawing::Point(33, 67);
			this->radioButton2->Name = L"radioButton2";
			this->radioButton2->Size = System::Drawing::Size(216, 19);
			this->radioButton2->TabIndex = 5;
			this->radioButton2->TabStop = true;
			this->radioButton2->Text = L"Data Encryption Standard (DES)";
			this->radioButton2->UseVisualStyleBackColor = true;
			this->radioButton2->CheckedChanged += gcnew System::EventHandler(this, &Form1::radioButton2_CheckedChanged);
			// 
			// radioButton1
			// 
			this->radioButton1->AutoSize = true;
			this->radioButton1->Location = System::Drawing::Point(33, 33);
			this->radioButton1->Name = L"radioButton1";
			this->radioButton1->Size = System::Drawing::Size(246, 19);
			this->radioButton1->TabIndex = 0;
			this->radioButton1->TabStop = true;
			this->radioButton1->Text = L"Advanced Encryption Standard (AES)";
			this->radioButton1->UseVisualStyleBackColor = true;
			this->radioButton1->CheckedChanged += gcnew System::EventHandler(this, &Form1::radioButton1_CheckedChanged);
			// 
			// textBox2
			// 
			this->textBox2->Font = (gcnew System::Drawing::Font(L"Georgia", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->textBox2->Location = System::Drawing::Point(217, 294);
			this->textBox2->Multiline = true;
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(557, 59);
			this->textBox2->TabIndex = 5;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Georgia", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->label2->Location = System::Drawing::Point(20, 315);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(135, 16);
			this->label2->TabIndex = 6;
			this->label2->Text = L"Encrypted Message :";
			// 
			// pictureBox1
			// 
			this->pictureBox1->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"pictureBox1.Image")));
			this->pictureBox1->Location = System::Drawing::Point(103, 137);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(128, 130);
			this->pictureBox1->TabIndex = 7;
			this->pictureBox1->TabStop = false;
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(7, 14);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(813, 490);
			this->Controls->Add(this->pictureBox1);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->groupBox1);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Font = (gcnew System::Drawing::Font(L"Georgia", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->Name = L"Form1";
			this->Text = L"COMMAND CENTER";
			this->Load += gcnew System::EventHandler(this, &Form1::Form1_Load);
			this->groupBox1->ResumeLayout(false);
			this->groupBox1->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion


	private: System::Void textBox1_TextChanged(System::Object^  sender, System::EventArgs^  e) 
			 {

			 }


	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) 
			 {

				if(value==1)
				{
				 cipherdata = textBox1->Text;
				 plainbytes = Encoding::ASCII->GetBytes(cipherdata);
				 plainkey = Encoding::ASCII->GetBytes("0123456789abcdef");
				 desObj->Key = plainkey;
				 desObj->Mode = CipherMode::CBC;
				 desObj->Padding = PaddingMode::Zeros;

				 MemoryStream^ ms = gcnew MemoryStream();
				 CryptoStream^ cs = gcnew CryptoStream(ms, desObj->CreateEncryptor(), CryptoStreamMode::Write);

				 cs->Write(plainbytes, 0, plainbytes->Length);
				 cs->Close();

				 cipherbytes = ms->ToArray();
				 ms->Close();
				 textBox2->Text = Encoding::ASCII->GetString(cipherbytes);
				}
				else if(value==2)
				{
					DESCryptoServiceProvider^ DesAlg = gcnew DESCryptoServiceProvider;
					desdata = textBox1->Text;
					
					descipher = EncryptTextToMemory(desdata, DesAlg->Key, DesAlg->IV);
					textBox2->Text = Encoding::ASCII->GetString(descipher);

					Final = DecryptTextFromMemory(descipher, DesAlg->Key, DesAlg->IV);
					//MessageBox::Show("For now DES Algorithm is under construction");
					/*DES ALGORITHM*/
				}
				else if(value==3)
				{
					cipherdata = textBox1->Text;
					data = Encoding::ASCII->GetBytes(cipherdata);
					RSACryptoServiceProvider^ rsa = gcnew RSACryptoServiceProvider();

					cdata = RSAEncrypt(data, rsa->ExportParameters(false), false);
					rbytes = RSADecrypt(cdata, rsa->ExportParameters(true), false);

					textBox2->Text = Encoding::ASCII->GetString(cdata);
					/*RSA Algorithm*/
				}
				else
					MessageBox::Show("Please Select an Algoritm First");
			 }
	private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e) 
		 {

			 if (value==1)
			 {
				MessageBox::Show("Message Sent Sucessfully..!!!");
				this->Hide();
				Form2^ f2 = gcnew Form2(textBox2->Text, cipherbytes, rbytes, desObj, textBox1->Text, value, Final);
				f2->ShowDialog();
			 }
			 else if (value == 2)
			 {
				 MessageBox::Show("Message Sent Sucessfully..!!!");
				this->Hide();
				Form2^ f2 = gcnew Form2(textBox2->Text, cipherbytes, rbytes, desObj, textBox1->Text, value, Final);
				f2->ShowDialog();
			 }
			 else
			 {
				MessageBox::Show("Message Sent Sucessfully..!!!");
				this->Hide();
				Form2^ f2 = gcnew Form2(textBox2->Text, cipherbytes, rbytes, desObj, textBox1->Text, value, Final);
				f2->ShowDialog();
			 }
		 }
	private: System::Void Form1_Load(System::Object^  sender, System::EventArgs^  e) {
		 }
		
	private: System::Void radioButton1_CheckedChanged(System::Object^  sender, System::EventArgs^  e) 
		 {
		value=1;
		 }
	private: System::Void radioButton2_CheckedChanged(System::Object^  sender, System::EventArgs^  e) 
		 {
		value=2;
		 }
	private: System::Void radioButton3_CheckedChanged(System::Object^  sender, System::EventArgs^  e) 
		 {
		 value=3;
		 }

};
}