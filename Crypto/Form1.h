#include "stdafx.h"
#include <stdint.h>
#include <string>
#include<iostream>
#pragma once
#include "Form2.h"
#include "udp.h"
int value=0;
int value1 = 0;


#define RECEIVE_IP          "127.0.0.1"
unsigned short ReceivingPort = 8005;

UdpInSocket inSocket_Ownship1(RECEIVE_IP,  ReceivingPort);

UdpOutSocket outSocket_Ownship2(RECEIVE_IP,  ReceivingPort);

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

	/* Decryption using DES Algortihm */
	array<Byte> ^DecryptTextFromMemory( array<Byte>^ Data, array<Byte>^ Key, array<Byte>^ IV )
	{
		try
			{

				 MemoryStream^ msDecrypt = gcnew MemoryStream( Data );
				 //Creating a new instance of CryptoStream Memory.
				 CryptoStream^ csDecrypt = gcnew CryptoStream( msDecrypt,(gcnew DESCryptoServiceProvider)->CreateDecryptor( Key, IV ),CryptoStreamMode::Read );
				 array<Byte> ^fromEncrypt = gcnew array<Byte>(Data->Length);

				 csDecrypt->Read( fromEncrypt, 0, fromEncrypt->Length );
				 return fromEncrypt;
			}
		catch ( CryptographicException^ e ) 
			{
				 Console::WriteLine( "A Cryptographic error occurred: {0}", e->Message );
				 return nullptr;
			}
	} 

	/* Hashing Function using SHA-256 .NET */
	int DisplayHashCode( String^ Operand )
	{
		int HashCode = Operand->GetHashCode();
		return HashCode;
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
		String^ sign;
		array<Byte>^ rbytes;
		array<Byte>^ descipher;
		array<Byte>^ signcipher;
		array<Byte> ^cipherbytes2;
		SymmetricAlgorithm^ desObj;
		SymmetricAlgorithm^ desObj1;
		RSACryptoServiceProvider^ rsaObj;

	private: System::Windows::Forms::TextBox^  textBox3;
	public: 
	private: System::Windows::Forms::TextBox^  textBox4;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::Button^  button3;
	private: Microsoft::VisualBasic::PowerPacks::ShapeContainer^  shapeContainer1;
	private: Microsoft::VisualBasic::PowerPacks::LineShape^  lineShape2;
	private: Microsoft::VisualBasic::PowerPacks::LineShape^  lineShape1;
	private: System::Windows::Forms::MenuStrip^  menuStrip1;
	private: System::Windows::Forms::ToolStripMenuItem^  quitToolStripMenuItem;


	private: System::Windows::Forms::PictureBox^  pictureBox1;
	
	public:
		Form1(void)
		{
			InitializeComponent();
			// Intialization of AES Algorithm Object.
			desObj = Rijndael::Create();
			desObj1 = Rijndael::Create();

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
		/// Required method for Designer support - do not modify  COMPLETE DESIGNER TOOLS AND CODE
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
			this->textBox3 = (gcnew System::Windows::Forms::TextBox());
			this->textBox4 = (gcnew System::Windows::Forms::TextBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->shapeContainer1 = (gcnew Microsoft::VisualBasic::PowerPacks::ShapeContainer());
			this->lineShape2 = (gcnew Microsoft::VisualBasic::PowerPacks::LineShape());
			this->lineShape1 = (gcnew Microsoft::VisualBasic::PowerPacks::LineShape());
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->quitToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->groupBox1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox1))->BeginInit();
			this->menuStrip1->SuspendLayout();
			this->SuspendLayout();
			// 
			// button1
			// 
			this->button1->Font = (gcnew System::Drawing::Font(L"Georgia", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->button1->Location = System::Drawing::Point(103, 492);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(154, 58);
			this->button1->TabIndex = 0;
			this->button1->Text = L"ENCRYPT";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &Form1::button1_Click);
			// 
			// button2
			// 
			this->button2->Enabled = false;
			this->button2->Font = (gcnew System::Drawing::Font(L"Georgia", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->button2->Location = System::Drawing::Point(580, 492);
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
			this->textBox1->Location = System::Drawing::Point(217, 53);
			this->textBox1->Multiline = true;
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(557, 59);
			this->textBox1->TabIndex = 2;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Georgia", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(28, 72);
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
			this->groupBox1->Location = System::Drawing::Point(317, 132);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(383, 145);
			this->groupBox1->TabIndex = 4;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"Select Encryption Method (Signature)";
			// 
			// radioButton3
			// 
			this->radioButton3->AutoSize = true;
			this->radioButton3->Location = System::Drawing::Point(33, 114);
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
			this->radioButton2->Location = System::Drawing::Point(33, 81);
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
			this->radioButton1->Location = System::Drawing::Point(33, 47);
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
			this->textBox2->Location = System::Drawing::Point(217, 393);
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
			this->label2->Location = System::Drawing::Point(20, 415);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(135, 16);
			this->label2->TabIndex = 6;
			this->label2->Text = L"Encrypted Message :";
			// 
			// pictureBox1
			// 
			this->pictureBox1->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"pictureBox1.Image")));
			this->pictureBox1->Location = System::Drawing::Point(27, 173);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(128, 130);
			this->pictureBox1->TabIndex = 7;
			this->pictureBox1->TabStop = false;
			// 
			// textBox3
			// 
			this->textBox3->Location = System::Drawing::Point(217, 320);
			this->textBox3->Multiline = true;
			this->textBox3->Name = L"textBox3";
			this->textBox3->Size = System::Drawing::Size(136, 47);
			this->textBox3->TabIndex = 8;
			// 
			// textBox4
			// 
			this->textBox4->Location = System::Drawing::Point(638, 319);
			this->textBox4->Multiline = true;
			this->textBox4->Name = L"textBox4";
			this->textBox4->Size = System::Drawing::Size(136, 47);
			this->textBox4->TabIndex = 9;
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(247, 296);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(72, 14);
			this->label3->TabIndex = 10;
			this->label3->Text = L"Signature :";
			// 
			// button3
			// 
			this->button3->Location = System::Drawing::Point(456, 319);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(75, 47);
			this->button3->TabIndex = 11;
			this->button3->Text = L"Encrypt";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &Form1::button3_Click);
			// 
			// shapeContainer1
			// 
			this->shapeContainer1->Location = System::Drawing::Point(0, 0);
			this->shapeContainer1->Margin = System::Windows::Forms::Padding(0);
			this->shapeContainer1->Name = L"shapeContainer1";
			this->shapeContainer1->Shapes->AddRange(gcnew cli::array< Microsoft::VisualBasic::PowerPacks::Shape^  >(2) {this->lineShape2, 
				this->lineShape1});
			this->shapeContainer1->Size = System::Drawing::Size(840, 568);
			this->shapeContainer1->TabIndex = 12;
			this->shapeContainer1->TabStop = false;
			// 
			// lineShape2
			// 
			this->lineShape2->Name = L"lineShape2";
			this->lineShape2->X1 = 359;
			this->lineShape2->X2 = 446;
			this->lineShape2->Y1 = 339;
			this->lineShape2->Y2 = 339;
			// 
			// lineShape1
			// 
			this->lineShape1->Name = L"lineShape1";
			this->lineShape1->X1 = 538;
			this->lineShape1->X2 = 625;
			this->lineShape1->Y1 = 340;
			this->lineShape1->Y2 = 340;
			// 
			// menuStrip1
			// 
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) {this->quitToolStripMenuItem});
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Size = System::Drawing::Size(840, 24);
			this->menuStrip1->TabIndex = 13;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// quitToolStripMenuItem
			// 
			this->quitToolStripMenuItem->Name = L"quitToolStripMenuItem";
			this->quitToolStripMenuItem->Size = System::Drawing::Size(42, 20);
			this->quitToolStripMenuItem->Text = L"Quit";
			this->quitToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::quitToolStripMenuItem_Click);
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(7, 14);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(840, 568);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->textBox4);
			this->Controls->Add(this->textBox3);
			this->Controls->Add(this->pictureBox1);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->groupBox1);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->menuStrip1);
			this->Controls->Add(this->shapeContainer1);
			this->Font = (gcnew System::Drawing::Font(L"Georgia", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->MainMenuStrip = this->menuStrip1;
			this->Name = L"Form1";
			this->Text = L"COMMAND CENTER";
			this->groupBox1->ResumeLayout(false);
			this->groupBox1->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox1))->EndInit();
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) 
			 {
				if (value1 == 1)
				{
					/* Creation of an Hash value to the entered message that is about to be passed */
					button2->Enabled = true;
					int^ hashval = DisplayHashCode(textBox1->Text);
					String^ hashstr = hashval->ToString();
					/* Writing that SHA-256 value into a file */
					StreamWriter^ outfile = gcnew StreamWriter("Hash.txt");
					outfile->Write(hashstr); 
					outfile->Close();

					if(value==1)
					{
						/* Creation of Encrypted Message using AES Algortihm */
						cipherdata = textBox1->Text;
						plainbytes = Encoding::ASCII->GetBytes(cipherdata);
						plainkey = Encoding::ASCII->GetBytes("0123456789abcdef");
						desObj->Key = plainkey;
						desObj->Mode = CipherMode::CBC;
						desObj->Padding = PaddingMode::Zeros;

						/* Creation of an memory stream to write in all the encrypted values */
						MemoryStream^ ms = gcnew MemoryStream();

						/* Calling the inbuit funcitons from the AESCryptoServiceProvider Class */
						CryptoStream^ cs = gcnew CryptoStream(ms, desObj->CreateEncryptor(), CryptoStreamMode::Write);

						cs->Write(plainbytes, 0, plainbytes->Length);
						cs->Close();
						cipherbytes = ms->ToArray();
						ms->Close();

						/* Writing the encrypted text onto an textbox */
						textBox2->Text = Encoding::ASCII->GetString(cipherbytes);
					}
					else if(value==2)
					{
						/* Creation of Encrypted Message using DES Algortihm */
						DESCryptoServiceProvider^ DesAlg = gcnew DESCryptoServiceProvider;
						desdata = textBox1->Text;

						/* Calling the inbuit funcitons from the DESCryptoServiceProvider Class */					
						descipher = EncryptTextToMemory(desdata, DesAlg->Key, DesAlg->IV);

						/* Writing the encrypted text onto an textbox */
						textBox2->Text = Encoding::ASCII->GetString(descipher);

						Final = DecryptTextFromMemory(descipher, DesAlg->Key, DesAlg->IV);
					}
					else if(value==3)
					{
						/* Creation of Encrypted Message using RSA Algortihm */
						cipherdata = textBox1->Text;
						data = Encoding::ASCII->GetBytes(cipherdata);
						RSACryptoServiceProvider^ rsa = gcnew RSACryptoServiceProvider();

						/* Calling the inbuit funcitons from the RSACryptoServiceProvider Class */
						cdata = RSAEncrypt(data, rsa->ExportParameters(false), false);
						rbytes = RSADecrypt(cdata, rsa->ExportParameters(true), false);

						/* Writing the encrypted text onto an textbox */
						textBox2->Text = Encoding::ASCII->GetString(cdata);
					}
					else
						/* Condition to ensure that an algorithm is checked before encryption */
						MessageBox::Show("Please Select an Algoritm First");
				}
				else
				{
					/* Condition to ensure that an digital signature is entred before encryption */
					MessageBox::Show("Type in your Signature and Encrypt it..!!");
				}
			 }
	private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e) 
		 {
			 /* Performs message sending operation and
			 Writing the intermediate encrypted value onto a text file for future decryption*/
			 StreamWriter^ outfile = gcnew StreamWriter("Intermi.txt");
			 outfile->Write(textBox2->Text); 
			 outfile->Close();

			 if (value==1)
			 {
				MessageBox::Show("Message Sent Sucessfully..!!!");
				this->Hide();
				/* Calling the second form Form2 from From1 by passing the arguments */
				Form2^ f2 = gcnew Form2(textBox2->Text, cipherbytes, rbytes, desObj, textBox1->Text, value, Final, signcipher, sign);
				f2->ShowDialog();
			 }
			 else if (value == 2)
			 {
				MessageBox::Show("Message Sent Sucessfully..!!!");
				this->Hide();
				/* Calling the second form Form2 from From1 by passing the arguments */
				Form2^ f2 = gcnew Form2(textBox2->Text, cipherbytes, rbytes, desObj, textBox1->Text, value, Final, signcipher, sign);
				f2->ShowDialog();
			 }
			 else
			 {
				MessageBox::Show("Message Sent Sucessfully..!!!");
				this->Hide();
				/* Calling the second form Form2 from From1 by passing the arguments */
				Form2^ f2 = gcnew Form2(textBox2->Text, cipherbytes, rbytes, desObj, textBox1->Text, value, Final, signcipher, sign);
				f2->ShowDialog();
			 }
		 }

	private: System::Void radioButton1_CheckedChanged(System::Object^  sender, System::EventArgs^  e) 
		 {
			 /* Setting value if AES algorithm is checked*/
			 value=1;
		 }
	private: System::Void radioButton2_CheckedChanged(System::Object^  sender, System::EventArgs^  e) 
		 {
			 /* Setting value if DES algorithm is checked*/
			 value=2;
		 }
	private: System::Void radioButton3_CheckedChanged(System::Object^  sender, System::EventArgs^  e) 
		 {
			 /* Setting value if AES algorithm is checked*/
			 value=3;
		 }

private: System::Void button3_Click(System::Object^  sender, System::EventArgs^  e)
		 {
			 /* Encrpyts the Digital Signature enterd by the user */
			 value1 = 1;
			 sign = textBox3->Text;

			 /* Using AES Algorithm */
			 array<Byte> ^plainbytes2 = Encoding::ASCII->GetBytes(sign);
			 array<Byte> ^plainkey2 = Encoding::ASCII->GetBytes("0123456789abcdef");
			 desObj1->Key = plainkey2;
			 desObj1->Mode = CipherMode::CBC;
			 desObj1->Padding = PaddingMode::Zeros;

			 /* Creation of an memory stream to write in all the encrypted values */
			 MemoryStream^ ms = gcnew MemoryStream();
			 CryptoStream^ cs = gcnew CryptoStream(ms, desObj1->CreateEncryptor(), CryptoStreamMode::Write);

			 cs->Write(plainbytes2, 0, plainbytes2->Length);
			 cs->Close();

			 cipherbytes2 = ms->ToArray();
			 ms->Close();
			 /* Displaying it onto a text box */
			 textBox4->Text = Encoding::ASCII->GetString(cipherbytes2);
			 
		 }

private: System::Void quitToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e)
		 {
			 /* MENU STRIP to Quit from the application */
			 if(MessageBox::Show("Do you want to exit?","My Application", MessageBoxButtons::YesNo,MessageBoxIcon::Question) == System::Windows::Forms::DialogResult::Yes)
			 {
				 Application::Exit();
			 }
		 }

};
}