void main()
{
    demo *p1 = new demo(4);
    demo *p2 = new demo(5);
    demo *p3 = new demo(*p2);
    
    cout << *p1 << *p2;
    if (p1->f1() && p2->f1()) {
        cout << f2(p3);
    }
    *p1 = *p2+25;
    cout << *p1;
}