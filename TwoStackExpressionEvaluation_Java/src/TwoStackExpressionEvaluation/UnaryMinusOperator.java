package ac.um.ds.TwoStackExpressionEvaluation;

public class UnaryMinusOperator extends Operator
{
	public UnaryMinusOperator()
	{
		super("_", 5, ASSOC_RIGHT, true);
	}
	@Override
	public double evaluate(double v1, double v2)
	{
		return -v1;
	}
}