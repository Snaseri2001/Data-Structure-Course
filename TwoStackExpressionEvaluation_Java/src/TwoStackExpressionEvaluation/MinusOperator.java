package ac.um.ds.TwoStackExpressionEvaluation;

public class MinusOperator extends Operator
{
	public MinusOperator()
	{
		super("-", 2,  ASSOC_LEFT, false);
	}
	@Override
	public double evaluate(double v1, double v2)
	{
		return v1 - v2;
	}
}