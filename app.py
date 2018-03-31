from flask import Flask , render_template
from tryserial import*
app = Flask(__name__, static_url_path='/static')
@app.route("/")
def main():
    return render_template('index.html', t=temp, wl=waterlevel, h=humidity, sm=soilmoist )

if __name__== "__main__":
    app.run()
