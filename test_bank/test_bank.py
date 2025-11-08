from bank import value

def test_value():
    assert value("Greetings") == 100
    assert value("Hello") == 0
    assert value("Hey there") == 20


