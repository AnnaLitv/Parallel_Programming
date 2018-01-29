with Ada.Text_IO; 
use Ada.Text_IO;
with Data;
with Ada.Integer_Text_IO; 
use Ada.Integer_Text_IO;

with System;
 procedure Lab_1 is
 
 N: constant Integer := 2000;
 package ConcreteData is new Data(N);
	use ConcreteData;
-----------------------------------
		task Fun1 with CPU=>0 is
			pragma Priority(1);
			pragma Storage_Size(900_000_000);
		end Fun1;

		task Fun2 with CPU=>1 is
			pragma Priority(1);
			pragma Storage_Size(900_000_000);
		end Fun2;

		task Fun3 with CPU=>2 is
			pragma Priority(1);
			pragma Storage_Size(100_000_000);
		end Fun3;
 ---------------------------
 task body Fun1  is

	begin
	Func1;
 end Fun1;
 ---------------------------
 task body Fun2 is
 begin
 Func2;
 end Fun2;
 ---------------------------
 task body Fun3 is
 begin
-- null;
 Func3;
 end Fun3;
 ---------------------------
 begin
 Put_Line("Hello!");
 end Lab_1;