from fuel import convert, gauge
import pytest

def test_convert():
    assert convert("1/5") == 20
    with pytest.raises(ValueError):
        convert("-1/5")
    with pytest.raises(ValueError):
        convert("7/5")

    with pytest.raises(ZeroDivisionError):
        convert("1/0")

def test_gauge():
    assert gauge(99) == "F"
    assert gauge(50) == "50%"
    assert gauge(1) == "E"
