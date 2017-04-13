using System;

using namespace std;

#pragma region Structs
public struct Ball
{
public:
	int _icolor;
	bool _exists;
	bool _isDisappearing;
	int _vel;
	int _yvel;
}

public struct Turn
{
public:
	int _itColor;
	int _itposX[];
	int _itposY[];
	int _column[];
}
#pragma endregion

public class Engine {
	#pragma region Variables

	private System.ComponentModel.IContainer components;

	public Ball[, ] _ball;
	private Ball[, ] _restart;
	private MainForm _MF;
	public Turn[] _turn;

	private int[] _X;
	private int[] _Y;
	private int _index;

	#pragma endregion
};

