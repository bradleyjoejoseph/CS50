from twttr import shorten

def test_shorten():
    assert shorten("bradley") == "brdly"
    assert shorten("bradley1") == "brdly1"
    assert shorten("BrAdley.") == "Brdly."

