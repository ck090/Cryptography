#pragma once
#include <time.h>
//#include "msclr\marshal_cppstd.h"

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
	//using namespace System::Globalization;
	//using namespace System::Collections;


	public ref class Form2 : public System::Windows::Forms::Form
	{

	public:
		String ^word;
		array<Byte>^ desfinal;
		array<Byte> ^cbytes; 
		array<Byte> ^frbytes;
		array<Byte> ^rawbytes;
		String ^byte2; 
		static int hi = 0;
		SymmetricAlgorithm^ dObj;
		SymmetricAlgorithm^ desObj2;
		String ^word2;

	private: System::Windows::Forms::TextBox^  textBox1;


	private: System::Windows::Forms::Button^  button5;
	private: System::Windows::Forms::TextBox^  textBox4;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::Button^  button6;
	public: 

	public: 
		String ^main;
		//String ^falstr;

	public:
		Form2(void)
		{
			InitializeComponent();
			//desObj2 = Rijndael::Create();
		}

		/* Hashing Function using SHA-256 .NET */
		int DisplayHasCode( String^ Operand )
		{
			int HasCode = Operand->GetHashCode();
			return HasCode;
		}

		Form2(String ^Text, array<Byte> ^cipher, array<Byte> ^rbytes, SymmetricAlgorithm^ desObj, String ^Text2, int vv, array<Byte>^ Final, array<Byte>^ signcipher, String^ sign)
		{
			InitializeComponent();
			word = Text;
			cbytes = cipher;
			dObj = desObj;
			main = Text2;
			hi = vv;
			rawbytes = rbytes;
			desfinal = Final;
			byte2 = sign;
		}


	protected:

		~Form2()
		{
			if (components)
			{
				delete components;
			}
		}

		String^ cipherdata;
		array<Byte>^ plainbytes2;

	private: System::Windows::Forms::Label^  label2;
	protected: 
	private: System::Windows::Forms::TextBox^  textBox2;
	private: System::Windows::Forms::Label^  label1;

	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::Button^  button2;
	private: System::Windows::Forms::Button^  button3;
	private: System::Windows::Forms::Button^  button4;


	private:
		
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		
		void InitializeComponent(void)
		{
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->button5 = (gcnew System::Windows::Forms::Button());
			this->textBox4 = (gcnew System::Windows::Forms::TextBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->button6 = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Georgia", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->label2->Location = System::Drawing::Point(29, 402);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(119, 16);
			this->label2->TabIndex = 10;
			this->label2->Text = L"Original Message :";
			this->label2->Click += gcnew System::EventHandler(this, &Form2::label2_Click);
			// 
			// textBox2
			// 
			this->textBox2->Font = (gcnew System::Drawing::Font(L"Georgia", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->textBox2->Location = System::Drawing::Point(217, 379);
			this->textBox2->Multiline = true;
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(557, 59);
			this->textBox2->TabIndex = 9;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Georgia", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(28, 58);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(120, 16);
			this->label1->TabIndex = 8;
			this->label1->Text = L"Crypted Message :";
			// 
			// textBox1
			// 
			this->textBox1->Font = (gcnew System::Drawing::Font(L"Georgia", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->textBox1->Location = System::Drawing::Point(217, 39);
			this->textBox1->Multiline = true;
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(557, 60);
			this->textBox1->TabIndex = 7;
			this->textBox1->TabStop = false;
			// 
			// button1
			// 
			this->button1->Enabled = false;
			this->button1->Font = (gcnew System::Drawing::Font(L"Georgia", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->button1->Location = System::Drawing::Point(397, 292);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(213, 62);
			this->button1->TabIndex = 11;
			this->button1->Text = L"DECRYPT";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &Form2::button1_Click);
			// 
			// button2
			// 
			this->button2->Font = (gcnew System::Drawing::Font(L"Georgia", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->button2->Location = System::Drawing::Point(348, 498);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(163, 43);
			this->button2->TabIndex = 12;
			this->button2->Text = L"SAVE ENTIRE TO TEXT";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &Form2::button2_Click);
			// 
			// button3
			// 
			this->button3->Font = (gcnew System::Drawing::Font(L"Georgia", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->button3->Location = System::Drawing::Point(14, 499);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(170, 43);
			this->button3->TabIndex = 13;
			this->button3->Text = L"SAVE THE CIPHERED TEXT";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &Form2::button3_Click);
			// 
			// button4
			// 
			this->button4->Font = (gcnew System::Drawing::Font(L"Georgia", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->button4->Location = System::Drawing::Point(660, 498);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(168, 43);
			this->button4->TabIndex = 14;
			this->button4->Text = L"QUIT";
			this->button4->UseVisualStyleBackColor = true;
			this->button4->Click += gcnew System::EventHandler(this, &Form2::button4_Click);
			// 
			// button5
			// 
			this->button5->Font = (gcnew System::Drawing::Font(L"Georgia", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->button5->Location = System::Drawing::Point(540, 149);
			this->button5->Name = L"button5";
			this->button5->Size = System::Drawing::Size(96, 47);
			this->button5->TabIndex = 17;
			this->button5->Text = L"VERIFY";
			this->button5->UseVisualStyleBackColor = true;
			this->button5->Click += gcnew System::EventHandler(this, &Form2::button5_Click);
			// 
			// textBox4
			// 
			this->textBox4->Font = (gcnew System::Drawing::Font(L"Georgia", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->textBox4->Location = System::Drawing::Point(359, 149);
			this->textBox4->Multiline = true;
			this->textBox4->Name = L"textBox4";
			this->textBox4->Size = System::Drawing::Size(136, 47);
			this->textBox4->TabIndex = 18;
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Georgia", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->label3->Location = System::Drawing::Point(394, 125);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(72, 14);
			this->label3->TabIndex = 19;
			this->label3->Text = L"Signature :";
			// 
			// button6
			// 
			this->button6->Enabled = false;
			this->button6->Font = (gcnew System::Drawing::Font(L"Georgia", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->button6->Location = System::Drawing::Point(359, 231);
			this->button6->Name = L"button6";
			this->button6->Size = System::Drawing::Size(277, 30);
			this->button6->TabIndex = 20;
			this->button6->Text = L"Verify Hashing";
			this->button6->UseVisualStyleBackColor = true;
			this->button6->Click += gcnew System::EventHandler(this, &Form2::button6_Click);
			// 
			// Form2
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(841, 555);
			this->Controls->Add(this->button6);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->textBox4);
			this->Controls->Add(this->button5);
			this->Controls->Add(this->button4);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->textBox1);
			this->Name = L"Form2";
			this->Text = L"SHOOTER NETWORK";
			this->Load += gcnew System::EventHandler(this, &Form2::Form2_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

	private: System::Void Form2_Load(System::Object^  sender, System::EventArgs^  e) {
					//textBox1->Text = word;
					StreamReader^ infile = gcnew StreamReader("C:\\Users\\Administrator.MCS-337\\Desktop\\All\\Crypto\\Crypto\\Crypto\\Intermi.txt");
					String^ rd = infile->ReadLine();
					textBox1->Text = rd;
					infile->Close();
			
			 }

	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
				 if (hi == 1)
				 {
					MemoryStream^ ms2 = gcnew MemoryStream(cbytes);
					CryptoStream^ cs2 = gcnew CryptoStream(ms2, dObj->CreateDecryptor(), CryptoStreamMode::Read);


					cs2->Read(cbytes, 0, cbytes->Length);
					plainbytes2 = ms2->ToArray();


					cs2->Close();
					ms2->Close();
					textBox2->Text = Encoding::ASCII->GetString(plainbytes2);
					
				 }
				 if (hi == 2)
				 {
					textBox2->Text = Encoding::ASCII->GetString(desfinal); 
				 }
				 if (hi == 3)
				 {
					textBox2->Text = Encoding::ASCII->GetString(rawbytes);
				 }

			 }

	private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e) {
				 StreamWriter^ outfile = gcnew StreamWriter("C:\\Users\\Administrator.MCS-337\\Desktop\\All\\Crypto\\Crypto\\Text_files\\EntireData.txt");
				 outfile->Write("Original Message : " + main + "\r\n\r\n\r\n"); 
				 outfile->Write("Encrypted Code : " + word + "\r\n\r\n\r\n");
				 outfile->Write("Decrypted Code : " + textBox2->Text);
				 outfile->Close();
				 MessageBox::Show("The Entire Data saved in a Text File");
			 }

	private: System::Void button3_Click(System::Object^  sender, System::EventArgs^  e) {
				 StreamWriter^ outfile2 = gcnew StreamWriter("C:\\Users\\Administrator.MCS-337\\Desktop\\All\\Crypto\\Crypto\\Text_files\\CipheredData.txt");
				 outfile2->Write("Encrypted Code : " + word + "\r\n\r\n\r\n");
				 outfile2->Close();
				 MessageBox::Show("The Encrypted Data saved in a Text File");

			}

	private: System::Void button4_Click(System::Object^  sender, System::EventArgs^  e) {
				 Application::Exit();
		 }

	public: System::Void button5_Click(System::Object^  sender, System::EventArgs^  e) {

				String ^sign = textBox4->Text;
				StreamReader^ infile = gcnew StreamReader("C:\\Users\\Administrator.MCS-337\\Desktop\\All\\Crypto\\Crypto\\Crypto\\Intermi.txt");
				String^ rd = infile->ReadLine();

				if(hi == 1)
				{
					if(sign == byte2) 
					{
						//button1->Enabled = true;
						button6->Enabled = true;
					}
					else
						MessageBox::Show("Hashing Error", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
				}

				if(hi == 2)
				{
					if(sign == byte2) {
						//button1->Enabled = true;
						button6->Enabled = true;
					}
					else
						MessageBox::Show("Hashing Error", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
				}

				if(hi == 3)
				{
					if(sign == byte2) {
						//button1->Enabled = true;
						button6->Enabled = true;
					}
					else
						MessageBox::Show("Hashing Error", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
				}
		 }

private: System::Void label2_Click(System::Object^  sender, System::EventArgs^  e) {
		 }
private: System::Void button6_Click(System::Object^  sender, System::EventArgs^  e) {
			 String^ decstr;
			 if (hi == 1)
				 {
					MemoryStream^ ms1 = gcnew MemoryStream(cbytes);
					CryptoStream^ cs1 = gcnew CryptoStream(ms1, dObj->CreateDecryptor(), CryptoStreamMode::Read);


					cs1->Read(cbytes, 0, cbytes->Length);
					plainbytes2 = ms1->ToArray();


					cs1->Close();
					ms1->Close();
					decstr = Encoding::ASCII->GetString(plainbytes2);
					//MessageBox::Show(decstr);
					
				 }
			 	 if (hi == 2)
				 {
					decstr = Encoding::ASCII->GetString(desfinal); 
					//MessageBox::Show(decstr);
				 }
				 if (hi == 3)
				 {
					decstr = Encoding::ASCII->GetString(rawbytes);
					//MessageBox::Show(decstr);
				 }
			 //String^ decstr = textBox2->Text;
			 MessageBox::Show(decstr);
			 int ^value2 = DisplayHasCode(decstr);
			 StreamWriter^ outfile = gcnew StreamWriter("C:\\Users\\Administrator.MCS-337\\Desktop\\All\\Crypto\\Crypto\\Crypto\\Hash2.txt");
			 outfile->Write(value2); 
			 outfile->Close();
			 StreamReader^ infile = gcnew StreamReader("C:\\Users\\Administrator.MCS-337\\Desktop\\All\\Crypto\\Crypto\\Crypto\\Hash.txt");
			 String^ rd = infile->ReadLine();
			 infile->Close();
			 MessageBox::Show(rd);
			 StreamReader^ infile2 = gcnew StreamReader("C:\\Users\\Administrator.MCS-337\\Desktop\\All\\Crypto\\Crypto\\Crypto\\Hash2.txt");
			 String^ rd2 = infile2->ReadLine();
			 infile2->Close();
			 MessageBox::Show(rd2);
			 if (rd == rd2)
			 {
				 button1->Enabled = true;
				 MessageBox::Show("Hash Values Match... NO TAMPERING OF MESSAGE");
			 }
			 else
			 {
				 MessageBox::Show("MESSAGE HAS BEEN TAMPERED", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
			 }
		 }
};
}
