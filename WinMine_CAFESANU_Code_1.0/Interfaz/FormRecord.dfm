object FormRec: TFormRec
  Left = 686
  Top = 343
  BorderIcons = [biSystemMenu, biMinimize]
  BorderStyle = bsNone
  Caption = 'WinMine CAFESANU'
  ClientHeight = 120
  ClientWidth = 198
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  Position = poMainFormCenter
  PixelsPerInch = 96
  TextHeight = 13
  object Label1: TLabel
    Left = 64
    Top = 8
    Width = 75
    Height = 13
    Caption = 'Tiene un record'
  end
  object Label2: TLabel
    Left = 72
    Top = 24
    Width = 63
    Height = 13
    Caption = 'en este nivel.'
  end
  object Label3: TLabel
    Left = 56
    Top = 40
    Width = 92
    Height = 13
    Caption = 'Escriba su Nombre.'
  end
  object edtRec: TEdit
    Left = 8
    Top = 56
    Width = 185
    Height = 21
    TabOrder = 0
    OnKeyUp = edtRecKeyUp
  end
  object Button1: TButton
    Left = 64
    Top = 88
    Width = 75
    Height = 25
    Caption = 'Aceptar'
    TabOrder = 1
    OnClick = Button1Click
  end
end
