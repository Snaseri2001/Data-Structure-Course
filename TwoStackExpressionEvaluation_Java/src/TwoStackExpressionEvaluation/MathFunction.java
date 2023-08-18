package ac.um.ds.TwoStackExpressionEvaluation;

// Copyright (C) Kamaledin Ghiasi-Shirazi, Ferdowsi Univerity of Mashhad, 2014 (1393 Hijri Shamsi)

import static ac.um.ds.TwoStackExpressionEvaluation.Operator.Associativity.ASSOC_RIGHT;

//
// Author: Kamaledin Ghiasi-Shirazi


public abstract class MathFunction extends Operator
{
	public MathFunction(String name)
	{
		super(name,6, ASSOC_RIGHT, true, Token.Type.FUNCTION);
	}
}