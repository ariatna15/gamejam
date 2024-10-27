#pragma once
#include "Carrito.h"
namespace GameJam {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Resumen de MyForm1
	/// </summary>
	public ref class MyForm1 : public System::Windows::Forms::Form
	{
	public:
		MyForm1(void)
		{
			InitializeComponent();
			//
			//TODO: agregar código de constructor aquí
			//
			canvas = this->CreateGraphics();
			ObjCarrito1 = new Carrito(50, 100, 50, 50, 6);
			ObjCarrito2 = new Carrito(50, 200, 50, 50, 5);
			ObjCarrito3 = new Carrito(50, 300, 50, 50, 4);
			Tiempotranscurrido = 0;
		}

	protected:
		/// <summary>
		/// Limpiar los recursos que se estén usando.
		/// </summary>
		~MyForm1()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Timer^ timer1;
	protected:
	private: System::ComponentModel::IContainer^ components;
		   Graphics^ canvas;
		   Carrito* ObjCarrito1;
		   Carrito* ObjCarrito2;
		   Carrito* ObjCarrito3;
		   int Tiempotranscurrido;

	private:
		/// <summary>
		/// Variable del diseñador necesaria.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Método necesario para admitir el Diseñador. No se puede modificar
		/// el contenido de este método con el editor de código.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->SuspendLayout();
			// 
			// timer1
			// 
			this->timer1->Enabled = true;
			this->timer1->Tick += gcnew System::EventHandler(this, &MyForm1::timer1_Tick);
			// 
			// MyForm1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1108, 601);
			this->Name = L"MyForm1";
			this->Text = L"MyForm1";
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void timer1_Tick(System::Object^ sender, System::EventArgs^ e) {
		static bool carreraTerminada = false;

		if (carreraTerminada) {
			return;
		}
		// Incrementar el tiempo transcurrido en cada tick del timer
		Tiempotranscurrido++;

		// Borrar el área del tiempo y redibujar el tiempo actualizado
		canvas->FillRectangle(Brushes::White, 10, 10, 200, 30);
		canvas->DrawString("Timer: " + Tiempotranscurrido.ToString() + " s", gcnew System::Drawing::Font("Arial", 12), Brushes::Black, 10, 10);

		if (ObjCarrito1 != nullptr) {
			ObjCarrito1->borrar(canvas);
			ObjCarrito1->mover(canvas);
			ObjCarrito1->dibujar(canvas);

			if (ObjCarrito1->getX() + ObjCarrito1->getW() >= canvas->VisibleClipBounds.Width) {
				carreraTerminada = true;
				return;
			}
		}

		if (ObjCarrito2 != nullptr) {
			ObjCarrito2->borrar(canvas);
			ObjCarrito2->mover(canvas);
			ObjCarrito2->dibujar(canvas);

			if (ObjCarrito2->getX() + ObjCarrito2->getW() >= canvas->VisibleClipBounds.Width) {
				carreraTerminada = true;
				return;
			}
		}

		if (ObjCarrito3 != nullptr) {
			ObjCarrito3->borrar(canvas);
			ObjCarrito3->mover(canvas);
			ObjCarrito3->dibujar(canvas);

			if (ObjCarrito3->getX() + ObjCarrito3->getW() >= canvas->VisibleClipBounds.Width) {
				carreraTerminada = true;
				return;
			}
		}


	}
	};
}
