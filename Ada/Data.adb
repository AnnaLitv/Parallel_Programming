
with Ada.Text_IO; 
use Ada.Text_IO;
with Ada.Integer_Text_IO, System.Multiprocessors; 
use Ada.Integer_Text_IO, System.Multiprocessors;

package body Data is
-----------------------------------------------------------
procedure Input_Vector1(V: out Vector; N: Integer) is


begin
for  ind in 1..N loop
				V(ind):=1;
			end loop;
end Input_Vector1;
-----------------------------------------------------------
procedure Input_Vector(V: out Vector; N: Integer) is


begin
for  ind in 1..N loop
				Get(V(ind));
			end loop;
end Input_Vector;
----------------------------------------------------------------
procedure Output_Vector(V: Vector; N: Integer) is
begin
for i in 1..N loop
			Put(V(i));
		end loop;
end Output_Vector;
----------------------------------------------------------------
procedure Input_Matrix1(M: out Matrix; N: Integer) is
begin
for  ind in 1..N loop
			for  indx in 1..N loop
				M(ind,indx):=1;
			end loop;
			end loop;
end Input_Matrix1;
---------------------------------------------------------------
procedure Input_Matrix(M: out Matrix; N: Integer) is
begin
for  ind in 1..N loop
			Put_Line("Enter the new line");
			for  indx in 1..N loop
				Get(M(ind,indx));
			end loop;
			end loop;
end Input_Matrix;
---------------------------------------------------------------
procedure Output_Matrix(M:  Matrix; N: Integer) is
begin
for  ind in 1..N loop 
			for  indx in 1..N loop
				Put(M(ind,indx));
			end loop;
			Put_Line(" ");
			end loop;
end Output_Matrix;
----------------------------------------------------------------
function Mult_Matrixes(MA, MB: in Matrix; N: Integer) return Matrix is

		result: Matrix;

	begin
		for i in 1..N loop
			for j in 1..N loop
				result(i, j) := 0;
				for k in 1..N loop
					result(i, j) := result(i, j) + MA(i, k) * MB(k, j);
				end loop;
			end loop;
		end loop;

		return result;
	end Mult_Matrixes;
----------------------------------------------------------------
function Mult_Vector_Matrix(A: in Vector; MB: in Matrix; N: Integer) return Vector is

		res: Vector;

	begin
		for i in 1..N loop
			res(i) := 0;
			for j in 1..N loop
				res(i) := res(i) + MB(j, i) * A(j);
			end loop;
		end loop;

		return res;
	end Mult_Vector_Matrix;
----------------------------------------------------------------
function Sum_Vectors(A, B: in Vector; N:Integer) return Vector is

		res: Vector;

	begin
		for i in 1..N loop
			res(i) := A(i) + B(i);
		end loop;

		return res;
	end Sum_Vectors;
----------------------------------------------------------------
function Sum_Matrices(MA, MB: in Matrix; N:Integer) return Matrix is

		res: Matrix;

	begin
		for i in 1..N loop
			for j in 1..N loop
				res(i, j) := MA(i, j) + MB(i, j);
			end loop;
		end loop;

		return res;
	end Sum_Matrices;
----------------------------------------------------------------
function Min_Vector(A: in Vector; N: Integer) return Integer is

	res: Integer;

	begin
		res := A(1);
		for i in 2..N loop
			if res > A(i) then
				res := A(i);
			end if;
		end loop;

		return res;
	end Min_Vector;
---------------------------------------------------------------
function Sort_Vector(A:in Vector; N: Integer)return Vector is

	res: Vector;
	buf: Integer;
	
	begin
	res:=A;
		for i in 1..N loop
			for j in i+1..N loop
				if res(i)>res(j) then
					buf:=res(i);
					res(i):=res(j);
					res(j):=buf;
				end if;
			end loop;
		end loop;
	return res;
end Sort_Vector;
----------------------------------------------------------------
function Mult_Scalar_Vector(a: in Integer; B: in Vector; N: Integer) return Vector is

		res: Vector;

	begin
		for i in 1..N loop
			res(i) := a * B(i);
		end loop;

		return res;
	end Mult_Scalar_Vector;
----------------------------------------------------------------
function Trans_Matrix(MA: Matrix; N: Integer) return Matrix is

	res: Matrix;
	buf: Matrix;
	
begin
	buf:=MA;
	for i in 1..N loop
			for j in 1..N loop
			begin
			res(i,j):=buf(j,i);
			res(j,i):=buf(i,j);		
			end;
			end loop;
	end loop;
	
	return res;
end Trans_Matrix;
----------------------------------------------------------------
procedure Func1 is
	N:Integer;
	A_V, B_V, C_V	  : Vector := ( others => 0 );
	MA_V, MD_V		  : Matrix;
begin
delay 5.0;
	Put_Line("task 1 started!");
	Put_Line("Enter the N: ");
	Get(N);
	Input_Vector1(B_V, N);
	Input_Vector1(C_V, N);
	Input_Matrix1(MA_V,N);
	Input_Matrix1(MD_V, N);
	A_V:=Mult_Vector_Matrix(Mult_Scalar_Vector(Min_Vector(C_V,N),B_V,N), Sum_Matrices(Mult_Matrixes(MA_V, MD_V, N),MD_V,N),N);
	if N<10 then
	Output_Vector(A_V,N);
	end if;
	Put_Line("task 1 finished!");
	delay 5.0;
end Func1;

procedure Func2 is
	N:Integer;

	MA_V, MD_V, MZ_V, MB_V, MK_V, FI_V, TH_V   :Matrix:= ( others => (others => 0) );
	
begin
delay 7.0;
	Put_Line("task 2 started!");
	Put_Line("Enter the N: ");
	Get(N);
	Input_Matrix1(MA_V, N);
	Input_Matrix1(MZ_V, N);
	Input_Matrix1(MB_V, N);
	MK_V:=Sum_Matrices(Mult_Matrixes(Mult_Matrixes(MA_V,MZ_V,N),MA_V,N),Trans_Matrix(MB_V,N),N);
	if N<10 then
	Output_Matrix(MK_V,N);
	end if;
	Put_Line("task 2 finished!");
end Func2;

procedure Func3 is
	N:Integer;
	
	R_V, S_V, O_V  :Vector:= ( others => 0 );
	MT_V, MP_V:Matrix:= ( others => (others => 0) );
	begin
	delay 9.0;
		Put_Line("task 3 started!");
		Put_Line("Enter the N: "); --ввoдим N
		Get(N);
		Input_Vector1(R_V, N);
		Input_Vector1(S_V, N);
		Input_Matrix1(MT_V, N);
		Input_Matrix1(MP_V, N);
		O_V:=Mult_Vector_Matrix(Sort_Vector(Sum_Vectors(R_V,S_V,N),N),Mult_Matrixes(MT_V,MP_V,N),N);
		if N<10 then
		Output_Vector(O_V,N);
		end if;
		Put_Line("task 3 finished!");
end Func3;


--------------------------------------------------------------------------

--------------------------------------------------------------------------

-------------------------------------------------------------------------
end Data;