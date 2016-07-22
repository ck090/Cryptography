#pragma once
#include <time.h>

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


	public ref class Form2 : public System::Windows::Forms::Form
	{

	public:
		/* Declaration of variables */ 
		String ^word;
		array<Byte>^ desfinal;
		array<Byte> ^cbytes; 
		array<Byte> ^frbytes;
		array<Byte> ^rawbytes;
		String ^byte2; 
		static int hi = 0;
		SymmetricAlgorithm^ dObj;
		SymmetricAlgorithm^ desObj2;
		String^ cipherdata;
		array<Byte>^ plainbytes2;
		String ^word2;
		String ^rd2;
		String^ rd3;
		String^ str;
		static int ^val = 0;

	private: System::Windows::Forms::TextBox^  textBox1;


	private: System::Windows::Forms::Button^  button5;
	private: System::Windows::Forms::TextBox^  textBox4;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::Button^  button6;
	private: System::Windows::Forms::Button^  button1;
	public: 

	public: 
		String ^main;

	public:
		Form2(void)
		{
			// Constructor to create the Form2
			InitializeComponent();
		}

		/* Form2 function where the passed values from Form1 to Form2 */
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
			// Destructor of delete the Form2
			if (components)
			{
				delete components;
			}
		}


	private: System::Windows::Forms::Label^  label2;
	protected: 
	private: System::Windows::Forms::TextBox^  textBox2;
	private: System::Windows::Forms::Label^  label1;


	private: System::Windows::Forms::Button^  button2;
	private: System::Windows::Forms::Button^  button3;
	private: System::Windows::Forms::Button^  button4;


	private:
		
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code

		// COMPLETE DESIGNER TOOLS AND CODE
		
		void InitializeComponent(void)
		{
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->button5 = (gcnew System::Windows::Forms::Button());
			this->textBox4 = (gcnew System::Windows::Forms::TextBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->button6 = (gcnew System::Windows::Forms::Button());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Georgia", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->label2->Location = System::Drawing::Point(29, 349);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(119, 16);
			this->label2->TabIndex = 10;
			this->label2->Text = L"Original Message :";
			// 
			// textBox2
			// 
			this->textBox2->Font = (gcnew System::Drawing::Font(L"Georgia", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->textBox2->Location = System::Drawing::Point(217, 326);
			this->textBox2->Multiline = true;
			this->textBox2->Name = L"textBox2";
			this->textBox2->PasswordChar = '*';
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
			this->button6->Location = System::Drawing::Point(359, 419);
			this->button6->Name = L"button6";
			this->button6->Size = System::Drawing::Size(277, 31);
			this->button6->TabIndex = 20;
			this->button6->Text = L"Verify Hashing";
			this->button6->UseVisualStyleBackColor = true;
			this->button6->Click += gcnew System::EventHandler(this, &Form2::button6_Click);
			// 
			// button1
			// 
			this->button1->Enabled = false;
			this->button1->Font = (gcnew System::Drawing::Font(L"Georgia", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->button1->Location = System::Drawing::Point(359, 234);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(277, 60);
			this->button1->TabIndex = 21;
			this->button1->Text = L"Decrypt";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &Form2::button1_Click_1);
			// 
			// Form2
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(841, 555);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->button6);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->textBox4);
			this->Controls->Add(this->button5);
			this->Controls->Add(this->button4);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->button2);
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

	private: System::Void Form2_Load(System::Object^  sender, System::EventArgs^  e) 
			 {
				 /* Initailzing Form2 with the Ciphered Text from From1, reading from a text file */
				 StreamReader^ infile = gcnew StreamReader("Intermi.txt");
				 String^ rd = infile->ReadLine();

				 /* Displaying the ciphered text on Form2 Load */
				 textBox1->Text = rd;
				 infile->Close();
			 }

	private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e)
			 {
				 /* Writing the Entire data trancation into a Text file usign output stream */
				 StreamWriter^ outfile = gcnew StreamWriter("C:\\Users\\Administrator.MCS-337\\Desktop\\All\\Crypto\\Crypto\\Text_files\\EntireData.txt");
				 outfile->Write("Original Message : " + main + "\r\n\r\n\r\n"); 
				 outfile->Write("Encrypted Code : " + word + "\r\n\r\n\r\n");
				 outfile->Write("Decrypted Code : " + textBox2->Text);
				 outfile->Close();
				 MessageBox::Show("The Entire Data saved in a Text File");
			 }

	private: System::Void button3_Click(System::Object^  sender, System::EventArgs^  e) 
			 {
				 /* Writing only the ciphered data into a Text file usign output stream */
				 StreamWriter^ outfile2 = gcnew StreamWriter("C:\\Users\\Administrator.MCS-337\\Desktop\\All\\Crypto\\Crypto\\Text_files\\CipheredData.txt");
				 outfile2->Write("Encrypted Code : " + word + "\r\n\r\n\r\n");
				 outfile2->Close();
				 MessageBox::Show("The Encrypted Data saved in a Text File");

			 }

	private: System::Void button4_Click(System::Object^  sender, System::EventArgs^  e) 
			 {
				 /* Button click to exit the application */
				 Application::Exit();
			 }

	public: System::Void button5_Click(System::Object^  sender, System::EventArgs^  e)
			 {
				/* To verify the signature of the user and let them to decrypt the cipherd message displayed */
				String ^sign = textBox4->Text;
				/* Reading the Hashed Code from the text file */
				StreamReader^ infile = gcnew StreamReader("Hash.txt");
				rd3 = infile->ReadLine();
				infile->Close();

				if(hi == 1)
				{
					if(sign == byte2) 
					{
						/* If the value of the Signature from Form1 matches with Form2 entered value */
						/* Then the button to decrypt and check to verify hashing will be available */
						button1->Enabled = true;
						button6->Enabled = true;
					}
					else
						/* If the signature don't match then report an error */
						MessageBox::Show("Signature Error", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
				}

				if(hi == 2)
				{
					if(sign == byte2) 
					{
						/* If the value of the Signature from Form1 matches with Form2 entered value */
						/* Then the button to decrypt and check to verify hashing will be available */
						button1->Enabled = true;
						button6->Enabled = true;
					}
					else
						/* If the signature don't match then report an error */
						MessageBox::Show("Signature Error", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
				}

				if(hi == 3)
				{
					if(sign == byte2) 
					{
						/* If the value of the Signature from Form1 matches with Form2 entered value */
						/* Then the button to decrypt and check to verify hashing will be available */
						button1->Enabled = true;
						button6->Enabled = true;
					}
					else
						/* If the signature don't match then report an error */
						MessageBox::Show("Signature Error", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
				}
     	  }

	private: System::Void button6_Click(System::Object^  sender, System::EventArgs^  e)  
			{
				/* To verify Hashing of both the Original Message and newly Decrypted Message */
				/* We call the hashcode function uses SHA-256 to find out the hash value */
				val = str->GetHashCode();
				String ^rd2 = val->ToString();
			
				if (rd3 == rd2)
				{
					/* If both the hash values are same then reveal the message and send a message*/
					textBox2->PasswordChar = '\0';
					MessageBox::Show("Hash Values Match... NO TAMPERING OF MESSAGE", "Success", MessageBoxButtons::OK, MessageBoxIcon::Asterisk);
				}
				else
				{
					/* If the Message has been tampered then donot display the decrypted message */
					MessageBox::Show("MESSAGE HAS BEEN TAMPERED", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
				}
			}

	private: System::Void button1_Click_1(System::Object^  sender, System::EventArgs^  e) 
			 {
				 /*  To Decrpyt the ciphered message which was recieved from Form1 */
				 if (hi == 1)
				 {
					 /* DEcryption using AES Algorithm by creating a new stream */
					 /* Calling the Function from AESCryptoServiceProvider Class */
					 MemoryStream^ ms1 = gcnew MemoryStream(cbytes);
					 CryptoStream^ cs1 = gcnew CryptoStream(ms1, dObj->CreateDecryptor(), CryptoStreamMode::Read);

					 /* Reading the value of cbytes from CryptoStream and converting it to an array */
					 cs1->Read(cbytes, 0, cbytes->Length);
					 plainbytes2 = ms1->ToArray();
					 cs1->Close();
					 ms1->Close();
					 /* Displaying it to a Textbox */
					 textBox2->Text = Encoding::ASCII->GetString(plainbytes2);
					
				 }
				else if (hi == 2)
				 {
					 /* DEcryption using DES Algorithm by creating a new stream */
					 /* Calling the Function from DESCryptoServiceProvider Class */
					 textBox2->Text = Encoding::ASCII->GetString(desfinal); 
				 }
				else
				 {
					 /* DEcryption using RSA Algorithm by creating a new stream */
					 /* Calling the Function from RSACryptoServiceProvider Class */
					 textBox2->Text = Encoding::ASCII->GetString(rawbytes);
				 }
				 str = textBox2->Text;
			 }

};
}

