double Calculate_money(string user_input)
{
  if (user_input[0] == '-' || user_input[0] == '+')
    user_input.insert(0, "0");
  string num_s = "";
  int flag = 1;
  double result = 0, tmp=0;
  for (int i = 0; i < user_input.length(); i++)
  {
    if （user_input[i] >= '0' && user_input[i] <= '9')
    {
      num_s.insert(num_s.length(), user_input.substr(i, 1));
      if (num_s.length() > 8)
      {
        cout << "Error: Input is too large!" << endl;
        return 0;
      }
    }
    else if (user_input[i] == '+' || user_input[i] == '-')
    {
      tmp = atof(num_s.c_str());
      result += (double)flag * tmp;
      tmp = 0;
      num_s = "";
      flag = (user_input[i] == '+' ? 1 : -1);
    }
    else 
    {
      cout << "Opps, wrong expression!" << endl;
      return 0;
    }
  }
  tmp = atof(num_s.c_str());
  result += (double)flag * tmp;
  if (result >= 100000000)
  {
    cout << "Error: Input is too large!" << endl;
    return 0;
  }
  return result;
}
