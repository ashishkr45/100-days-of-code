void removeDupli(string str)
{
    bool flag[256] = {false};
    string ans;
    for (int i = 0; str[i] != '\0'; i++)
    {
        if (!flag[str[i] - '0'])
        {
            ans += str[i];
        }
        flag[str[i] - '0'] = true;
    }

    for (int i = 0; ans[i] != '\0'; i++)
    {
        cout << ans[i];
    }
    cout << endl;
    return;
}