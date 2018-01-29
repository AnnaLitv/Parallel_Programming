generic
N: Integer;
package Data is

type Matrix is private;
type Vector is private;

	procedure Func1;
	procedure Func2;
	procedure Func3;
	procedure Input_Vector1(V: out Vector; N: Integer);
	procedure Output_Vector(V: Vector; N: Integer);
	procedure Input_Matrix1(M: out Matrix; N: Integer);
	procedure Output_Matrix(M:  Matrix; N: Integer);
	function Mult_Matrixes(MA, MB: in Matrix; N: Integer) return Matrix;
	function Mult_Vector_Matrix(A: in Vector; MB: in Matrix; N: Integer) return Vector;
	function Sum_Vectors(A, B: in Vector; N:Integer) return Vector;
	function Sum_Matrices(MA, MB: in Matrix; N:Integer) return Matrix;
	function Min_Vector(A: in Vector; N: Integer) return Integer;
	function Sort_Vector(A:in Vector; N: Integer)return Vector;
	function Mult_Scalar_Vector(a: in Integer; B: in Vector; N: Integer) return Vector;
	function Trans_Matrix(MA: Matrix; N: Integer) return Matrix;
	
	private
		
	type Vector is array(1..N) of Integer;
	type Matrix is array(1..N, 1..N) of Integer;
	
	
end Data;