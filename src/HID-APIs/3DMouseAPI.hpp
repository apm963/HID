#pragma once

3DMouseAPI::3DMouseAPI(void) : _button(false)
{
	// Empty
}

void 3DMouseAPI::begin(void)
{
	end();
}

void 3DMouseAPI::end(void)
{
	_button0 = false;
	_button1 = false;
	_button2 = false;
	rotate("x", 0);
	rotate("y", 0);
	rotate("z", 0);
	move("x", 0);
	move("y", 0);
	move("z", 0);
}

void 3DMouseAPI::click(int button)
{
	switch(button){
		case 0:
			_button0 = true;
			update(void);
			_button0 = false;
			update(void);
			break;
		case 0:
			_button1 = true;
			update(void);
			_button1 = false;
			update(void);
			break;
		case 0:
			_button2 = true;
			update(void);
			_button2 = false;
			update(void);
			break;
	}
}

void 3DMouseAPI::rotate(string axis, int16_t rotation)
{
	if(axis == "x")
		_xRot = rotation;
	if (axis == "y")
		_yRot = rotation;
	if (axis == "y")
		_zRot = rotation;
}

void 3DMouseAPI::move(string axis, int16_t pos)
{
	if (axis == "x")
		_x = pos;
	if (axis == "y")
		_y = pos;
	if (axis == "y")
		_z = pos;
}

void 3DMouseAPI::update(void)
{
	HID_3DMouseReport_Data_t report;
	report.button0 = _button0;
	report.button1 = _button1;
	report.button2 = _button2;
	report.xRot = _xRot;
	report.yRot = _yRot;
	report.zRot = _zRot;
	report.xAxis = _x;
	report.yAxis = _y;
	report.zAxis = _z;

	SendReport(&report, sizeof(report));
}

void 3DMouseAPI::button0(bool b)
{
	if (b != _button0)
	{
		_button0 = b;
		update();
	}
}

void 3DMouseAPI::button1(bool b)
{
	if (b != _button1)
	{
		_button1 = b;
		update();
	}
}

void 3DMouseAPI::button2(bool b)
{
	if (b != _button2)
	{
		_button2 = b;
		update();
	}
}



void 3DMouseAPI::press(int button)
{
	switch(button){
		case 0:
			button0(true);
			break;
		case 1:
			button1(true);
			break;
		case 2:
			button2(true);
			break;
	}
}

void 3DMouseAPI::release(void)
{
	switch (button)
	{
	case 0:
		button0(false);
		break;
	case 1:
		button1(false);
		break;
	case 2:
		button2(false);
		break;
	}
}

void 3DMouseAPI::releaseAll(void)
{
	_button0 = false;
	_button1 = false;
	_button2 = false;
	update();
}

bool 3DMouseAPI::isPressed()
{
	switch (button)
	{
	case 0:
		return _button0;
		break;
	case 1:
		return _button1;
		break;
	case 2:
		return _button2;
		break;
	}
}
