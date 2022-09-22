/*
* Copyright (c) 2022 XXIV
* 
* Permission is hereby granted, free of charge, to any person obtaining a copy
* of this software and associated documentation files (the "Software"), to deal
* in the Software without restriction, including without limitation the rights
* to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
* copies of the Software, and to permit persons to whom the Software is
* furnished to do so, subject to the following conditions:
* 
* The above copyright notice and this permission notice shall be included in all
* copies or substantial portions of the Software.
* 
* THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
* IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
* FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
* AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
* LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
* OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
* SOFTWARE.
*/
public class URLEncoding {

    static {
        System.loadLibrary("urlencodingjni");
    }
    
    /*
    * Percent-encodes every byte except alphanumerics and -, _, ., ~. Assumes UTF-8 encoding.
    * 
    * Example:
    * * *
    * String res = URLEncoding.encode("This string will be URL encoded.");
    * System.out.println(res);
    * * *
    * 
    * @param data
    * @return encoded string
    */ 
    public native static String encode(String data);
    
    /*
    * Percent-encodes every byte except alphanumerics and -, _, ., ~.
    * 
    * Example:
    * * *
    * String res = URLEncoding.encodeBinary("This string will be URL encoded.");
    * System.out.println(res);
    * * *
    * 
    * @param data
    * @return encoded string
    */ 
    public native static String encodeBinary(String data);
    
    /*
    * Decode percent-encoded string assuming UTF-8 encoding.
    * 
    * Example:
    * * *
    * String res = URLEncoding.encodeBinary("%F0%9F%91%BE%20Exterminate%21");
    * System.out.println(res);
    * * *
    * 
    * @param data
    * @return decoded string
    */
    public native static String decode(String data);
    
    /*
    * Decode percent-encoded string as binary data, in any encoding.
    * 
    * Example:
    * * *
    * String res = URLEncoding.encodeBinary("%F1%F2%F3%C0%C1%C2");
    * System.out.println(res);
    * * *
    * 
    * @param data
    * @return decoded string
    */
    public native static String decodeBinary(String data);
}